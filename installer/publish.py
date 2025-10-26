import os
import shutil
import fnmatch
import subprocess
import sys

import dload
import datetime
from git import Repo
import tomlkit
import semver
import filecmp

os.makedirs("publish", exist_ok=True)

def get_current_tag(repo: Repo):
    for tag in repo.tags:
        if tag.commit == repo.head.commit:
            return tag
    return None

repo = Repo("..")
assert not repo.bare
current_tag = get_current_tag(repo)

with open("userversion.txt", 'w') as f:
    with open("../modules/core/module.toml") as mod_file:
        mod = tomlkit.parse(mod_file.read())

    if current_tag is not None:
        f.write(current_tag.name)
        version = semver.Version.parse(current_tag.name)
        prelease = list(map(lambda v: int(v) if v.isdigit() else v, version.prerelease.split('.')))
        mod['version'] = [version.major, version.minor, version.patch] + prelease
    else:
        version = datetime.datetime.now().strftime("%Y%m%d")
        f.write(version)
        mod['version'][3] = 'nightly'
        mod['version'][4] = version

    with open("../modules/core/module.toml", 'w') as mod_file:
        tomlkit.dump(mod, mod_file)

# Download engine
dload.save_unzip("https://github.com/PiratesAhoy/storm-engine/releases/download/pa15.0.0-beta.6%2B4/storm-engine.release-steam-false.zip", "engine", delete_after=True)

published_files = set()
changed_files = set()
deleted_files = set()


def add_file(source_file, target_file=None):
    if target_file is None:
        target_file = os.path.basename(source_file)
    # Normalize target path under publish
    target_rel = target_file.lstrip("\\/")
    target_path = os.path.normpath(os.path.join("publish", target_rel))
    os.makedirs(os.path.dirname(target_path), exist_ok=True)

    # Track this file as expected in the final publish folder
    published_files.add(target_path)

    # Skip copying if destination exists and content is unchanged
    if os.path.exists(target_path):
        try:
            src_stat = os.stat(source_file)
            dst_stat = os.stat(target_path)
            if src_stat.st_size == dst_stat.st_size:
                # If timestamps are effectively equal, assume unchanged
                if abs(src_stat.st_mtime - dst_stat.st_mtime) < 1e-6:
                    return
                # Same size but different mtime — do a deep comparison to be sure
                try:
                    if filecmp.cmp(source_file, target_path, shallow=False):
                        return
                except OSError:
                    pass
        except OSError:
            # If any error occurs, fall back to copying
            pass

    shutil.copy2(source_file, target_path)
    # Record that this file changed in publish (new or updated)
    changed_files.add(target_path)


def add_directory(path, target=None):
    for base, dirs, files in os.walk(path):
        for file in files:
            fn = os.path.join(base, file)
            add_file(fn, fn.replace(path, target or ""))

def add_pattern(pattern, directory=None, target=None):
    if directory is None:
        directory = "."
    for base, dirs, files in os.walk(directory):
        for file in files:
            if fnmatch.fnmatch(os.path.basename(file), pattern):
                fn = os.path.join(base, file)
                add_file(fn, fn.replace(directory, target or ""))

# The listing of files to add
# _____________________________________________________________________________
def copy_files():
    add_file("engine/engine.exe")
    add_file("engine/config.exe")
    add_file("engine/crashpad_handler.exe")
    add_file("engine/engine.pdb")
    add_file("engine/fmod.dll")
    add_file("engine/mimalloc.dll")
    add_file("engine/mimalloc-redirect.dll")

    # 7zip executable is required for uploading logs
    add_file("resources/7za.exe")

    add_file("../.itch.toml")
    add_file("resources/engine.ini")
    add_file("resources/build14_beta4_final", "resource/build14_beta4_final")

    add_pattern("*.h", directory="engine/resource", target="resource")
    add_pattern("*.fx", directory="engine/resource", target="resource")

    add_pattern("*.c", directory="../PROGRAM", target="PROGRAM")
    add_pattern("*.h", directory="../PROGRAM", target="PROGRAM")

    add_directory("../Documentation", target="Documentation")

    # Modules
    add_pattern("*.toml", directory="../modules", target="modules")

    # Resources
    add_pattern("*.ini", directory="../RESOURCE", target="resource")
    add_pattern("*.toml", directory="../RESOURCE", target="resource")
    add_pattern("*.txt", directory="../RESOURCE", target="resource")
    add_pattern("*.ani", directory="../RESOURCE", target="resource")
    add_pattern("*.an", directory="../RESOURCE", target="resource")
    add_pattern("*.zap", directory="../RESOURCE", target="resource")
    add_pattern("*.grs", directory="../RESOURCE", target="resource")
    add_pattern("*.ptc", directory="../RESOURCE", target="resource")

    # Audio and video
    add_pattern("*.ogg", directory="../RESOURCE", target="resource")
    add_pattern("*.mp3", directory="../RESOURCE", target="resource")
    add_pattern("*.wav", directory="../RESOURCE", target="resource")
    add_pattern("*.flac", directory="../RESOURCE", target="resource")
    add_pattern("*.wmv", directory="../RESOURCE", target="resource")

    # Models
    add_pattern("*.gm", directory="../RESOURCE", target="resource")
    add_pattern("*.col", directory="../RESOURCE", target="resource")

    # Particles
    add_pattern("*.xps", directory="../RESOURCE", target="resource")
    add_pattern("*.xml", directory="../RESOURCE", target="resource")

    # Textures
    add_pattern("*.tx", directory="../RESOURCE", target="resource")
    add_pattern("*.tga", directory="../RESOURCE", target="resource")
    add_pattern("*.jpg", directory="../RESOURCE", target="resource")
    add_pattern("*.png", directory="../RESOURCE", target="resource")

    # Fonts
    add_pattern("*.fnt", directory="../RESOURCE", target="resource")

copy_files()

# Remove files in publish that are no longer part of this build

def cleanup_publish_folder():
    existing_files = set()
    for base, dirs, files in os.walk("publish"):
        for file in files:
            existing_files.add(os.path.normpath(os.path.join(base, file)))

    obsolete = existing_files - published_files
    for path in obsolete:
        try:
            os.remove(path)
            deleted_files.add(path)
        except OSError:
            pass

    # Remove empty directories bottom-up
    for base, dirs, files in os.walk("publish", topdown=False):
        for d in dirs:
            p = os.path.join(base, d)
            try:
                if not os.listdir(p):
                    os.rmdir(p)
            except OSError:
                pass

cleanup_publish_folder()

# Decide whether to run Butler based on significant changes
mod_publish_path = os.path.normpath(os.path.join("publish", "modules", "core", "module.toml"))
exclusions = {mod_publish_path}

all_changes = set(map(os.path.normpath, changed_files | deleted_files))
significant_changes = [p for p in all_changes if p not in exclusions]

if not significant_changes and current_tag is None:
    print("No significant changes detected (only module version/userversion updates). Skipping Butler push.")
else:
    # Publish to itch.io
    channel = "nightly-windows" if current_tag is None else "windows"
    butler_command = f"butler push publish cmdrhammie/beyond-new-horizons:{channel} --if-changed --userversion-file userversion.txt"
    print(f"Running '{butler_command}'")
    process = subprocess.Popen(butler_command, stdout=subprocess.PIPE)
    for c in iter(lambda: process.stdout.read(1), b""):
        sys.stdout.buffer.write(c)

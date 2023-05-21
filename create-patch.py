import subprocess
import os
# import py7zr
from zipfile import ZipFile, ZIP_LZMA
import re
import shutil

version = subprocess.run(["git", "describe", "--tags", "--abbrev=0"], stdout=subprocess.PIPE).stdout.decode("utf-8").strip()
print("Creating patch for version " + version)

# Check if version number is correct in script files
with open("PROGRAM/globals.c", "r") as globals_file:
    globals_content = globals_file.read()
    script_version = re.search(r'#define BUILDVERSION\W+"(\d+\.\d+\.\d+(\-[a-z]+\.\d+)?)"', globals_content)
    if script_version is None:
        raise Exception("No valid version number found in globals.c!")
    if script_version.group(1) != version:
        raise Exception("Version number in globals.c does not match latest tag " + version + " != " + script_version.group(1))

files = subprocess.run(['git', '--no-pager', 'diff', '--name-only', '--diff-filter=d', "15.0.0-alpha.9.."],
                       stdout=subprocess.PIPE).stdout.decode("utf-8").replace('"', '').split("\n")

def add_directory(z, path, target = None):
    for base, dirs, files in os.walk(path):
        for file in files:
            fn = os.path.join(base, file)
            # print(fn)
            add_file(fn, fn.replace(path, target or ""))

def add_file(source_file, target_file=None):
    # z.write(source_file, target_file)
    if target_file is None:
        target_file = source_file
    target_path = "installer/patch/" + target_file
    os.makedirs(os.path.dirname(target_path), exist_ok=True)
    shutil.copy2(source_file, target_path)

with ZipFile('patch.zip', 'a', compression=ZIP_LZMA) as z:
    for file in files:
        if file != "" and file != "engine.ini" and not file.startswith("installer/") and not file.startswith("RESOURCE/") and not file.endswith(".py"):
            add_file(file)
    add_file("installer/resources/engine.ini", 'engine.ini')
    add_file("installer/engine/crashpad_handler.exe", 'crashpad_handler.exe')
    add_file("installer/engine/engine.exe", 'engine.exe')
    add_file("installer/engine/engine.pdb", 'engine.pdb')
    add_file("installer/engine/fmod.dll", 'fmod.dll')
    add_file("installer/engine/mimalloc.dll", 'mimalloc.dll')
    add_file("installer/engine/mimalloc-redirect.dll", 'mimalloc-redirect.dll')
    add_directory(z, "installer/engine/resource", "RESOURCE")
    # Particles where not included in installer
    add_directory(z, "RESOURCE/Particles", "RESOURCE/Particles")

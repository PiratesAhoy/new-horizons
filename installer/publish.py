import os
import shutil
import fnmatch

shutil.rmtree("publish")

os.makedirs("publish", exist_ok=True)

def add_file(source_file, target_file=None):
    if target_file is None:
        target_file = os.path.basename(source_file)
    target_path = "publish/" + target_file
    os.makedirs(os.path.dirname(target_path), exist_ok=True)
    shutil.copy2(source_file, target_path)


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

add_file("engine/engine.exe")
add_file("engine/crashpad_handler.exe")
add_file("engine/engine.pdb")
add_file("engine/fmod.dll")
add_file("engine/mimalloc.dll")
add_file("engine/mimalloc-redirect.dll")

add_file("../.itch.toml")
add_file("resources/engine.ini")
add_file("resources/build14_beta4_final", "RESOURCE/build14_beta4_final")

add_pattern("*.h", directory="engine/resource", target="RESOURCE")
add_pattern("*.fx", directory="engine/resource", target="RESOURCE")

add_pattern("*.c", directory="../PROGRAM", target="PROGRAM")
add_pattern("*.h", directory="../PROGRAM", target="PROGRAM")

add_directory("../Documentation", target="Documentation")

# Resources
add_pattern("*.ini", directory="../RESOURCE", target="RESOURCE")
add_pattern("*.txt", directory="../RESOURCE", target="RESOURCE")
add_pattern("*.ani", directory="../RESOURCE", target="RESOURCE")
add_pattern("*.an", directory="../RESOURCE", target="RESOURCE")
add_pattern("*.zap", directory="../RESOURCE", target="RESOURCE")
add_pattern("*.grs", directory="../RESOURCE", target="RESOURCE")
add_pattern("*.ptc", directory="../RESOURCE", target="RESOURCE")

# Audio and video
add_pattern("*.ogg", directory="../RESOURCE", target="RESOURCE")
add_pattern("*.wav", directory="../RESOURCE", target="RESOURCE")
add_pattern("*.flac", directory="../RESOURCE", target="RESOURCE")
add_pattern("*.wmv", directory="../RESOURCE", target="RESOURCE")

# Models
add_pattern("*.gm", directory="../RESOURCE", target="RESOURCE")
add_pattern("*.col", directory="../RESOURCE", target="RESOURCE")

# Particles
add_pattern("*.xps", directory="../RESOURCE", target="RESOURCE")
add_pattern("*.xml", directory="../RESOURCE", target="RESOURCE")

# Textures
add_pattern("*.tx", directory="../RESOURCE", target="RESOURCE")
add_pattern("*.tga", directory="../RESOURCE", target="RESOURCE")
add_pattern("*.jpg", directory="../RESOURCE", target="RESOURCE")
add_pattern("*.png", directory="../RESOURCE", target="RESOURCE")

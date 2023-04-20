import subprocess
import os
# import py7zr
from zipfile import ZipFile, ZIP_LZMA
import re

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

files = subprocess.run(['git', '--no-pager', 'diff', '--name-only', '--diff-filter=d', "15.0.0-alpha.1.."],
                       stdout=subprocess.PIPE).stdout.decode("utf-8").replace('"', '').split("\n")

def add_directory(z, path, target = None):
    for base, dirs, files in os.walk(path):
        for file in files:
            fn = os.path.join(base, file)
            print(fn)
            z.write(fn, fn.replace(path, target or ""))

with ZipFile('patch.zip', 'w', compression=ZIP_LZMA) as z:
    for file in files:
        if file != "" and not file.startswith("installer/") and not file.endswith(".py"):
            z.write(file)
    z.write("installer/resources/engine.ini", 'engine.ini')
    z.write("E:/Projects/PiratesAhoy/storm-engine/cmake-build-release/bin/crashpad_handler.exe", 'crashpad_handler.exe')
    z.write("E:/Projects/PiratesAhoy/storm-engine/cmake-build-release/bin/engine.exe", 'engine.exe')
    z.write("E:/Projects/PiratesAhoy/storm-engine/cmake-build-release/bin/engine.pdb", 'engine.pdb')
    z.write("E:/Projects/PiratesAhoy/storm-engine/cmake-build-release/bin/fmod.dll", 'fmod.dll')
    z.write("E:/Projects/PiratesAhoy/storm-engine/cmake-build-release/bin/mimalloc.dll", 'mimalloc.dll')
    z.write("E:/Projects/PiratesAhoy/storm-engine/cmake-build-release/bin/mimalloc-redirect.dll", 'mimalloc-redirect.dll')
    add_directory(z, "E:/Projects/PiratesAhoy/storm-engine/cmake-build-release/bin/resource", "RESOURCE")
    # Particles where not included in installer
    add_directory(z, "RESOURCE/Particles", "RESOURCE/Particles")

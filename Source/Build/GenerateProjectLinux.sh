#!/bin/bash

# All paths are from the project root
fromScript() {
    Source/ThirdParty/Premake5/bin/premake5_linux --file=Source/Build/Scripts/premake5.lua $arg1
}

# Paths are relative to the build directory, go to premake and back
fromDir() {
    cd ..
    cd ThirdParty/Premake5/bin

    premake5_linux --file=../../../Build/Scripts/premake5.lua $arg1

    cd ../../..
    cd Build
}

# First argument provided
arg1=$1
# Argument count
argC=$#

# Ran from cmd in the build directory
if [ $argC -eq 1 ]; then
    fromDir
# Ran from the python script in the project root
elif [ $argC -eq 2 ]; then
    fromScript
else
    # Error, no argument was passed, branch straight to the end
    echo "Check Mappings.txt and provide an argument to this script!"
    exit 1
fi



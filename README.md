# RW Engine

This repository contains the source code for the RW runtime and tools. It also contains an example project using the engine and editor files.

## Table of contents

- [Building](#building)
	- [Universal build script](#universal-build-script)
	- [Platform Specific](#platform-specific)
		- [Windows](#windows)
		- [Linux](#linux)
		- [MacOS](#macos)
- [Creating a project](#creating-your-own-project)

## Building

To build the project files, you can either:

 - Run the build script in the project root.
 - Run a platform-specific script in `Source/Build/`.
 - Manually run premake in `Source/ThirdParty/premake/bin/` and use the file `Source/Build/Scripts/premake5.lua`.

The list of all availble generators can be found at `Source/Build/Mappings.txt`.

### Universal build script

Requires [Python 3.0](https://www.python.org/) or greater.

Run `GenerateProject.py`, it will prompt you to select a generator.

### Platform specific

#### Windows

1. `cd Source/Build`.
2. Run `GenerateProjectWindows.bat <generator>`.

#### Linux

Not yet implemented.

#### MacOS

Not yet implemented.

## Creating your own project
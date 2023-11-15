# Building

 * [Requirements](#requirements)
 * [Python build script](#python-build-script)
   * [Speeding up the build script](#speeding-up-the-build-script)
 * [Manual scripts](#manual-scripts)

## Requirements

 * [Python 3.0](https://www.python.org/) or later (optionally for the build script)

## Python build script

Running `GenerateProject.py` will prompt you to select a generator, from the list in `Source/Build/Mappings.txt`.

After selecting, the script will call Premake5 which is located at `Source/ThirdParty/Premake5/bin/` with the arguments `--file=Source/Build/Scripts/premake5.lua`.

### Speeding up the build script

If you do not want to input the same generator each time you build or are simply lazy, you can copy `Source/Build/GenerationPreferences.txt` to the root folder and then configure them from there.

The file needs to contain these 3 lines, even if you only plan to build on one of these platforms. (Example with default values)
```
windows=vs2022
linux=gmake2
macos=gmake2
```

## Manual scripts

If you do not have Python installed, you can instead go to `Source/Build/` and then run one of the following scripts depending on your platform.

```
GenerateProjectLinux.sh
GenerateProjectMacOS.sh
GenerateProjectWindows.bat
```

Make sure to provide only 1 argument to the scripts, this argument should be a key from `Mappings.txt`. Here is an example for calling these scripts on Windows.

```
 > cd Source/Build/
 > GenerateProjectWindows.bat vs2022
```
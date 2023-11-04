@echo off

@rem first argument provided
set arg1=%1
@rem argument count
set argC=0

@rem set argc
for %%x in (%*) do Set /A argC+=1

@rem ran from cmd in the build directory
if %argC%==1 goto fromDir
@rem ran from the python script in the project root
if %argC%==2 goto fromScript

@rem error, no argument was passed, branch straight to the end.
echo Check Mappings.txt and provide an argument to this script!
goto done

@rem
@rem all paths are from the project root
@rem
:fromScript
Source\ThirdParty\Premake5\bin\premake5.exe --file=Source/Build/Scripts/premake5.lua %arg1%
goto done

@rem
@rem paths are relative to the build directory, go to premake and back
@rem
:fromDir
cd ..\
cd ThirdParty\Premake5\bin

premake5 --file=../../../Build/Scripts/premake5.lua %arg1%

cd ..\..\..\
cd Build

@rem
@rem Finished!
@rem
:done

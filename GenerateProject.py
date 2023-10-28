# GenerateProject.py: A wrapper for the build scripts which are wrappers for premake.
# Sounds confusing but looks neat as a single file in the project root.
import platform, os

# Scuffed because every \ is replaced with \\
art = '''
  ______        ______  ____  _  __
 |  _ \\ \\      / / ___||  _ \\| |/ /
 | |_) \\ \\ /\\ / /\\___ \\| | | | ' / 
 |  _ < \\ V  V /  ___) | |_| | . \\ 
 |_| \\_\\ \\_/\\_/  |____/|____/|_|\\_\\
'''

# list of all options for premake
available_generators = []

# {position in available_generators: fancy description}
description_mappers = {}

# main "function"
if __name__ == "__main__":
    print(art)
    
    # Get the current platform the user is running on
    print("Detecting platform...")
    current_platform = platform.system() # 'Windows', 'Linux', 'Darwin'
    print("Found: " + current_platform) # f strings are a new thing, lets make this more accessible
    
    # Get mappings from build folder
    print("Reading Source/Build/Mappings.txt ...")
    
    with open("Source/Build/Mappings.txt") as file:
        generator_pos = 0
    
        for line in file:
            if line[0] != ";":
                split_line = line.split(": ")
                
                available_generators.append(split_line[0])
                description_mappers[generator_pos] = split_line[1].replace("\n", "")
                
                generator_pos += 1
    
    # Verbose 
    print("Possible generators: " + str(available_generators).replace("'", "").replace("[", "").replace("]", ""))
    
    # User input
    print("Pick an appropriate project generator:")
    for key in description_mappers:
        print("  " + str(key + 1) + " - " + description_mappers[key])
    
    pick = int(input("[Input number (int)]\n\t > "))
    
    # Pick correct generator
    action = available_generators[pick - 1]
    
    print("Using: " + description_mappers[pick - 1] + " (" + action + ")")
    
    if current_platform == "Windows":
        print("Running Source/Build/GenerateProjectWindows.bat " + action)
        
        os.system("Source\\Build\\GenerateProjectWindows.bat " + action + " frompythonscript")
    elif current_platform == "Linux":
        print("Not yet implemented!")
    elif current_platform == "Darwin":
        print("Not yet implemented!")
    else:
        print("An error has occured!")
    
    print("\nGenerateProject.py finished running")
else:
    print("Run this script, don't call it!")
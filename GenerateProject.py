# GenerateProject.py: A wrapper for the build scripts which are wrappers for premake.
# Sounds confusing but looks neat as a single file in the project root.
import platform, os

art = '''


    :::       ::: ::::::::::: :::::::::  ::::::::::          ::::::::  :::::::::  :::    ::: 
   :+:       :+:     :+:     :+:    :+: :+:                :+:    :+: :+:    :+: :+:   :+:   
  +:+       +:+     +:+     +:+    +:+ +:+                +:+        +:+    +:+ +:+  +:+     
 +#+  +:+  +#+     +#+     +#++:++#+  +#++:++#           +#++:++#++ +#+    +:+ +#++:++       
+#+ +#+#+ +#+     +#+     +#+    +#+ +#+                       +#+ +#+    +#+ +#+  +#+       
#+#+# #+#+#      #+#     #+#    #+# #+#                #+#    #+# #+#    #+# #+#   #+#       
###   ###   ########### #########  ##########          ########  #########  ###    ###       


'''

# List of all options for premake
available_generators = []

# {position in available_generators: fancy description}
description_mappers = {}

# If the preferences file exists
preferences_exist = False

# Build preferences
preferences = {}

# Main "function"
if __name__ == "__main__":
    print(art)
    
    # Get the current platform the user is running on
    print("Detecting platform...")
    current_platform = platform.system() # 'Windows', 'Linux', 'Darwin'
    print("Found: " + current_platform)
    
    # Check for preferences
    if os.path.isfile("GenerationPreferences.txt"):
        with open("GenerationPreferences.txt") as file:
            # Loop through each line
            for line in file:
                # If it's not a comment
                if line[0] != ";":
                    split_line = line.split("=")

                    # Sort by platform
                    if split_line[0] == "windows":
                        preferences["windows"] = split_line[1].replace("\n", "")
                    elif split_line[0] == "linux":
                        preferences["linux"] = split_line[1].replace("\n", "")
                    elif split_line[0] == "macos":
                        preferences["macos"] = split_line[1].replace("\n", "")

    # Check that all 3 preferences exist before skipping
    preferences_exist = len(preferences) == 3

    if preferences_exist:
        print("Found preferences (in /GenerationPreferences.txt), user input skipped")

        print("Using following preferences")

        for key, value in preferences.items():
            print("  " + key + ": " + value)

        # Set action based off current platform
        if current_platform == "Windows":
            action = preferences["windows"]
        elif current_platform == "Linux":
            action = preferences["linux"]
        elif current_platform == "Darwin":
            action = preferences["macos"]
    else:
        # Get mappings from build folder
        print("Reading Source/Build/Mappings.txt ...")
        
        # Open mappings
        with open("Source/Build/Mappings.txt") as file:
            generator_pos = 0
        
            # Loop through each line
            for line in file:
                # If it isn't a comment, add it to the available generators,
                # and add the description to the dictionary.
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
        
        pick = int(input("[Input number (int)]\n  > "))
        
        # Pick correct generator
        action = available_generators[pick - 1]
        
        print("Using: " + description_mappers[pick - 1] + " (" + action + ")")
    
    if current_platform == "Windows":
        print("Running 'Source/Build/GenerateProjectWindows.bat " + action + "'.")
        
        os.system("Source\\Build\\GenerateProjectWindows.bat " + action + " frompythonscript")
    elif current_platform == "Linux":
        print("Running 'Source/Build/GenerateProjectLinux.sh " + action + "'.")
        
        os.system("Source/Build/GenerateProjectLinux.sh " + action + " frompythonscript")
    elif current_platform == "Darwin":
        print("Running 'Source/Build/GenerateProjectMacOS.sh " + action + "'.")
        
        os.system("Source/Build/GenerateProjectMacOS.sh " + action + " frompythonscript")
    else:
        print("An error has occured!")
    
    print("\nGenerateProject.py finished running")
else:
    print("Run this script, don't call it!")
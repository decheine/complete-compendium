# This script cross checks the cmm (harvester/cmm/) and static/images/monsters/img
# to identify monster pages that should have an image but are missing it.
# 
# Iterate through each html file in harvester/cmm, it's name is the monster key
# Check monster .html file text for 
#   <img src="img/<monster_key>.gif" 
# 
# If found, check if <monster_key>.gif exists in static/images/mosnters/img
# If not, add this monster key to the list of monster keys with missing images. 


import os

missing_image_monsters = []

for monster_file_name in os.listdir("./harvester/cmm"):
    if os.path.isdir("./harvester/cmm/" + monster_file_name):
        print("Directory!")
    else:
        monster_key = monster_file_name[:-5]
        image_text_target = "<img src=\"img/" + monster_key + ".gif" 
        with open("./harvester/cmm/" + monster_file_name, encoding='utf-8') as f:
            monster_text = f.read()
            if image_text_target in monster_text:
                # print(monster_key)
                # print("Image")
                # Check for image in image directory
                if not os.path.isfile("./static/images/monsters/img/" + monster_key + ".gif"):
                    print(monster_key, "Image not found")
                    missing_image_monsters.append(monster_key)


print("Monster keys with missing images:")
print(missing_image_monsters)



report = open("./data/missing_images.txt", "w")

for key in missing_image_monsters:
    print(key)
    report.write(key + "\n")

report.close()

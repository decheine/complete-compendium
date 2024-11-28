// This script cross checks the cmm (harvester/cmm/) and static/images/monsters/img
// to identify monster pages that should have an image but are missing it.

// Iterate through each html file in harvester/cmm, it's name is the monster key
// Check if <monster_key>.gif exists in static/images/mosnters/img



console.log("Testing")

$.get("./harvester/cmm/aarakath.html")

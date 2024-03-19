
// Iterate through and asser that there exists entries for book_id's in the settings

const all_tsr = require('../data/all_tsr.json')

const settings_json = require('../data/settings.json')

const full_catalog = require('../src/data/Full_Catalog.json')

const ALL_MONSTERS = require('../src/data/ALL_MONSTERS.json')


// Make a list of monsters to their statblocks

// Monster Title, Monster Subtitle, Statblock
// {
//  monster_title: "",
//  monster_subtitle: "",
//  monster_key
//  statblock:
// } 
//

console.log("Compiling Climates")

monster_list = []
climates = {}
frequencies = {}
hitdice = {}

for (let monster_obj_index in ALL_MONSTERS){
    let monster_obj = {}
    let monster_title = ALL_MONSTERS[monster_obj_index]["monster_data"]["title"]
    let monster_key = ALL_MONSTERS[monster_obj_index]["monster_key"]
    if("statblock" in ALL_MONSTERS[monster_obj_index]["monster_data"] && ALL_MONSTERS[monster_obj_index]["monster_data"]["statblock"] != null){
        let statblock_titles = Object.keys(ALL_MONSTERS[monster_obj_index]["monster_data"]["statblock"])
        
        for(let statblock_title in statblock_titles){
            monster_list.push({
                title: monster_title,
                subtitle: statblock_titles[statblock_title],
                statblock: ALL_MONSTERS[monster_obj_index]["monster_data"]["statblock"][statblock_titles[statblock_title]]
            })
        }
        let climate = monster_list[monster_list.length - 1]["statblock"]["Climate/Terrain"]

        if(climate != undefined){
            if (climate in climates){
                climates[climate] += 1
            } else {
                if(climate.includes("/")){
                    let split_climate = climate.split("/")
                    for(let split_index in split_climate){
                        if (split_climate[split_index] in climates){ climates[split_climate[split_index]] += 1 }
                        else { climates[split_climate[split_index]] = 1}
                    }
                } else {
                    climates[climate] = 1
                }
            }
        }


        let frequency = monster_list[monster_list.length - 1]["statblock"]["Frequency"]

        if(frequency != undefined){
            if (frequency in frequencies){
                frequencies[frequency] += 1
            } else {
                if(frequency.includes("/")){
                    let split_frequency = frequency.split("/")
                    for(let split_index in split_frequency){
                        if (split_frequency[split_index] in frequencies){ frequencies[split_frequency[split_index]] += 1 }
                        else { frequencies[split_frequency[split_index]] = 1}
                    }
                } else {
                    frequencies[frequency] = 1
                }
            }
        }

        
        let hd = monster_list[monster_list.length - 1]["statblock"]["Hit Dice"]

        if(hd != undefined){
            if (hd in hitdice){
                hitdice[hd] += 1
            } else {
                if(hd == "N/A" || hd=="n/a"){
                    hitdice[hd] = 1
                } else {
                    // console.log(monster_key, hd)
                    // if(hd.includes("/")){
                    //     let split_hd = hd.split("/")
                    //     for(let split_index in split_hd){
                    //         if (split_hd[split_index] in hitdice){ hitdice[split_hd[split_index]] += 1 }
                    //         else { hitdice[split_hd[split_index]] = 1}
                    //     }
                    // } else {
                        hitdice[hd] = 1
                    // }
                }
            }
        }
        // console.log(monster_title, statblock_titles, monster_list[monster_list.length - 1]["statblock"]["Climate/Terrain"])
        
        monster_obj.title = monster_title
        // monster_obj.subtitle = 
        // console.log()
    } else {
        // Skip
    }
}

// console.log(climates)
// sort 
let sorted_climates = [...Object.entries(climates)].sort((a, b) => b[1] - a[1])

// for(let i in sorted_climates){
//     console.log(sorted_climates[i])
// }
console.log([...Object.entries(climates)].sort((a, b) => b[1] - a[1]))

console.log([...Object.entries(frequencies)].sort((a, b) => b[1] - a[1]))

console.log([...Object.entries(hitdice)].sort((a, b) => b[1] - a[1]))
console.log([...Object.values(hitdice)].sort((a, b) => b[1] - a[1]))
const all_tsr = require('../data/all_tsr.json')
const settings_json = require('../data/settings.json')


// const full_catalog = require('../src/data/Full_Catalog.json')


let all_tsr_new = {}


// For each entry in full_catalog
for(const [index, tsr] of Object.entries(all_tsr)) {
    // catalog_map[book_object.publish_id] = book_object
    // Check if this book_object's publish_id is also located in book_object["setting"] in settings_json
    // all_tsr_new[]
    
    var setting_obj = settings_json.filter(obj => {
        return obj.source_books.includes(index)
    })[0]
    console.log(index, setting_obj?.setting_name)
    all_tsr_new[index] = {
        title: tsr.title,
        year: tsr.year,
        author: tsr.author,
        setting: setting_obj.setting_name
    }
    // console.log(setting_obj)

    // if( setting_obj.source_books.includes(book_object.publish_id)){
    //     // Good
    // } else {
    //     console.error("Book ", book_object.publish_id, "not found in setting", setting_obj.setting_name)
    // }
    // console.log(book_object)
}

var fs = require('fs');
// fs.writeFile("./data/all_tsr_settings.json", JSON.stringify(all_tsr_new), function(err) {
//     if (err) {
//         console.log(err);
//     }
// });

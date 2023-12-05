
// Iterate through and asser that there exists entries for book_id's in the settings

const all_tsr = require('../data/all_tsr.json')

const settings_json = require('../data/settings.json')

const full_catalog = require('../src/data/Full_Catalog.json')


let results = {}


// For each entry in full_catalog
for(const [index, book_object] of full_catalog.entries()) {
    // catalog_map[book_object.publish_id] = book_object
    // Check if this book_object's publish_id is also located in book_object["setting"] in settings_json
    // console.log(book_object)

    var setting_obj = settings_json.filter(obj => {
        return obj.setting_name === book_object.setting
      })[0]
    // console.log(setting_obj)

    if( setting_obj?.source_books.includes(book_object.publish_id)){
        // Good
    } else {
        console.error("Book ", book_object.publish_id, "not found in setting", setting_obj?.setting_name)
    }
    // console.log(book_object)
}
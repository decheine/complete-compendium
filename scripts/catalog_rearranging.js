

const catalog_data = require('../src/data/Full_Catalog.json')

// console.log(catalog_data)
let catalog_map = {}

for(const [index, book_object] of catalog_data.entries()) {
    catalog_map[book_object.publish_id] = book_object
    // console.log(book_object)
}
// console.log(catalog_map)
// for (const [index, value] of books.entries()){
//     // console.log(index)
//     card_items.push(<BookCard key={value} id={value} category={props.category} title={BOOKS[value]}/> )
// }

const settingTitleToAcronym = require('../src/data/SettingTitleToAcronym.json')

// Make publish_id to acronym
let publishId_to_Acronym = {}

for(const [index, book_object] of Object.entries(catalog_map)) {
    catalog_map[book_object.publish_id] = book_object
    publishId_to_Acronym[index] = settingTitleToAcronym[book_object.setting]
    // console.log(book_object)
}

var fs = require('fs');
fs.writeFile("./src/data/catalog_map.json", JSON.stringify(catalog_map), function(err) {
    if (err) {
        console.log(err);
    }
});

fs.writeFile("./src/data/publishId_to_acronym.json", JSON.stringify(publishId_to_Acronym), function(err) {
    if (err) {
        console.log(err);
    }
});


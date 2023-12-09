//copyfile.js
const fs = require('fs');


// destination will be created or overwritten by default.
// output\json_files\AA_ALL_MONSTERS.json
fs.copyFile('output/json_files/AA_ALL_MONSTERS.json', 'src/data/ALL_MONSTERS.json', (err) => {
  if (err) throw err;
  console.log('Monster data copied to destination');
});

fs.copyFile('output/json_files/AA_Full_Catalog.json', 'src/data/Full_Catalog.json', (err) => {
  if (err) throw err;
  console.log('Catalog data was copied to destination');
});

fs.copyFile('output/json_files/AA_KEY_TITLES.json', 'src/data/AA_KEYS_TITLES.json', (err) => {
  if (err) throw err;
  console.log('Keys to Titles data was copied to destination');
});

// Create publish_id to setting_acr
// read in all_tsr
const all_tsr = require('../data/all_tsr.json')
const settingsTitletoAcronym = require('../src/data/SettingTitleToAcronym.json')
let publishId_to_acronym = {}
Object.entries(all_tsr).map(publish_id => {
  // console.log(publish_id[0], settingsTitletoAcronym[publish_id[1].setting])
  publishId_to_acronym[publish_id[0]] = settingsTitletoAcronym[publish_id[1].setting]
})

fs.writeFile("./src/data/publishId_to_acronym.json", JSON.stringify(publishId_to_acronym), function(err) {
  if (err) {
      console.log(err);
  }
});
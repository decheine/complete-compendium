//copyfile.js
const fs = require('fs');

// destination will be created or overwritten by default.
// output\json_files\AA_ALL_MONSTERS.json
fs.copyFile('output/json_files/AA_ALL_MONSTERS.json', 'src/data/ALL_MONSTERS.json', (err) => {
  if (err) throw err;
  console.log('File was copied to destination');
});

console.log("Building release bundle")


// Regexes for local html link fixes
//      Find: href="\/([^-]*?)\/"
//      Replace: href="./$1/index.html"
//      So far over 80k instances accross like 10k files. Might need notepad++ for this, have to do it in batches in vscode


// Do each layer on it's own. 

// 1. Home page index.html
//  
// 2. Catalog
//  2a Catalog Links
//  2b Catalog Images
// 3. Appendix Monster Pages
// 4. Catalog Monster Pages

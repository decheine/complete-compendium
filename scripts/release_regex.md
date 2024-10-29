
Do each layer on it's own. 

1. Home page index.html
   ```
   Find: href="\/([^-]*?)\/"
   Replace: href="./$1/index.html"
   ```

2. Catalog
   1. Catalog Links
   ```
   Find: href="\/([^-]*?)\/"
   Replace: href="../$1/index.html"
   ```
   2. Catalog Images
   ```
   Find: src="\/([^-]*?)"
   Replace: src="../$1"
   ```

3. Appendix
   1. Appendix Links
   ```
   Find: href="\/([^-]*?)\/"
   Replace: href="../$1/index.html"
   ```

4. Appendix Monster Pages
   1. Links (69,201 results)
   ```
   Find: href="\/([^-]*?)\/*"
   Replace: href="../../$1/index.html"
   ```
   2. Images
   ```
   Find: src="\/([^-]*?)"
   Replace: src="../../$1"
   ```

   Print pages, limit the search to ./appendix/*/print
   src="\/([^-]*?)"
   src="../../../$1"

5. Catalog Monster Pages - `./catalog/*/*/*/index.html`
   1. Links
   ```
   Find: href="\/([^-]*?)\/*"
   Replace: href="../../../../$1/index.html"
   ```
   2. Images
   ```
   Find: src="\/([^-]*?)"
   Replace: src="../../../../$1"
   ```

6. Catalog Book Pages
   1. Links
   ```
   Find: href="\/([^-]*?)\/*"
   Replace: href="../../../$1/index.html"
   ```
   2. Images
   ```
   Find: src="\/([^-]*?)"
   Replace: src="../../../$1"
   ```

7. Catalog Setting Pages
   1. Links
   ```
   Find: href="\/([^-]*?)\/*"
   Replace: href="../../$1/index.html"
   ```
   2. Images
   ```
   Find: src="\/([^-]*?)"
   Replace: src="../../$1"
   ```

Maybe Assign each monster it's own random monster link. Otherwise it just goes to the Appendix.
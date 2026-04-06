# Development Plan.md

Onwards to completing the compendium.

Towards a release and beyond:


## 
## Pre-release Beta

The following sections detail the tasks that must be completed for the pre-release beta.
Pre-release priority items will likely focus on design and architecture.

* [ ] Home page redesign that can accomodate rolling additional features, like the gallery, how-to, about, manual of the planes, etc. Also feature an area that links to the social media presence where I post updates and ideas. 
* [ ] Appendix design improvements and enhancements
  * [ ] Add filtering tools to Appendix other than raw text. 
  * [ ] Sticky navigation letters for each letter of the Appendix
  * [ ] "Redundancy Mode" toggle.
    * Toggle appendix displaying either only printed titles, 1:1 monster_key to title, or the current redundant list of all monster titles.   
* [ ] Catalog design improvements and enhancements
  * [ ]  Make a list view. Could also have the entries for the books for each setting contain it's monsters and links to them. Modes will be "Gallery", "List". Might be another mode but having all of the monsters visible in all of the books would make the base catalog page very resource intensive. Obviously it would have to be enabled and is not default but still. 
    * Gallery - Current view, with largish book covers, title, author, year, monster count, and tsr id
    * List - List view, does not have book covers (or very small), includes title, author, year, monster count, tsr id, and maybe some of the other publishing data, setting, all in one line so the list view is very dense. 
* [ ] Create processor to Generate a "raw" version that is standalone html with appendix and catalog, and maybe a few other pages. This would be the "offline" version. But more like a 'simplified' version. 
  * [ ] Going down this road could actually just lead it all back around to a raw html+css+js static site without the need for any framework. Because whatever 
* [ ] Social media account set up, with better donation method.
* [ ] Changelog established. 
* [ ] Improve contribution guidelines. 
* [ ] Software package cleanup, upgrade to modern packages and elinimate as many warning as possible.
* [ ] Create a normalized Climate/Terrain data field that is shared across monsters that share that climate/terrain but maybe not the same wording. 
  * Normalized categories would be the most prevalent spelling of each, likely from the core books. This can be related to assigning each monster a plane, too.
  * Might be tricky because monsters can have multiple climate/terrain types/biomes, so that data structure would have to capture each of them separately.
  * This could be pushed to Release, too.

## Release

The following items must be completed before the Compendium is considered 'released' to version 1.0, and is in Pre-release Beta before then. There may be some minor version increments for big updates, like for the Diablo book and Polyhedron collection. 

* [ ] All 2nd Edition Monsters
* [ ] All monster images
* [ ] Print page tools
* [ ] Monster variants (monster_key_TSR for variant pages.)
* [ ] Monster Gallery (like lomion)
* [ ] Manual of the Planes ("Other Worlds")
  * Baatezu promotion+demotion
  * For each monster, normalized data on it's origin plane. Monsters browsable by plane. 
  * List each book that talks about each plane. 
* [ ] TSR_Product_Matrix with all TSR products
  * Will include data such as publishing year (trying for month too), listed author, editors, artists, typesetters and other credits, as well as if the books contain monsters/spells/magic items/equipment/kits+classes/ 
  * Will feature products as early as Advanced Dungeons and Dragons, the earliest being the Monstrous Manual, and as late as any supporting the 2nd edition combat syste, which the latest was Die, Vecna, Die! if I'm not mistaken. 
* [ ] OPTIONAL | "Stables", a page with a collection of mounts and their sources. Also could be just a table.

## Expansions

The following items are proposed for a compendium of their own, eventually. These categories are to be tracked and captured in the TSR_Product_Matrix so transcription is smooth.

* AD&D 1e
  * I do want to eventually create a compendium for AD&D 1e monsters too, the ones that have movement in inches and just hit dice. Earliest being the Monstrous Manual. So the idea would be "All AD&D monsters since the Monstrous Manual".
* Magic Items
* Spells
* NPCs
* Other Equipment
* Classes, Kits
* Playable Races
* Potentially More.
  
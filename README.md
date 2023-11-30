
![A menagerie of fearsome monsters bannered with a title, Complete Compendium ](static/opengraph_banner.webp)

---

Live at [completecompendium.com](https://completecompendium.com)

# Complete Compendium - Advanced Dungeons & Dragons 2nd Edition

## What is the Complete Compendium?

This is a project to compile and catalog all monsters from the Advanced Dungeons & Dragons 2nd Edition tabletop roleplaying game. There are currently 23 campaign settings, over 200 books, and over 2000 unique monster pages, with still more to be catalogued.

These thousands of monster pages were scraped with the help of the Wayback machine from an old website at `lomion.de/cmm` that contained (almost) every AD&D 2nd Edition monster. The drawback was the site was minimally navigable, having only an appendix list. This project seeks to finish what the original creator started and catalog every monster, book, and setting from oldschool D&D. 


## The Data (the monsters)


`/cmm` is a submodule repository and the location of the data used to generate this static site at build time. It contains a C++ program that can run in a Docker container to harvest the monster data and output JSON data. 

Within `/cmm/cmm/` are a collection of HTML files, each being a monster page with its filename being that monster page's `monster_key` (e.g. `aarakath` or `zombie`). These HTML pages reference assets within sibling asset folders like monster images.

<details>
 <summary>Why this data format?</summary>

I chose to keep these as HTML files so that these files are functional on their own with nothing other than a web browser. I explored several database options but ended up with simple JSON files and static site generation. 

</details>



## Cataloguing Effort Tracking

There are a few undertakings that need to be done to complete the compendium. I will use GitHub's Issue tracking with tasks to track them all. These are:
* Validate Books: For each book in the Catalog, verify its monsters and add missing monster keys to catalog book pages. If monster doesn't exist, 
*  Add Missing Monsters: adding a new monster page and key, created from an HTML template. 
*  Add Missing Monster Images
*  Add Missing Book Covers
*  Dragon and Dungeon Magazines

###



## Running localling

Run development build

```
npm run develop
```

## Running monster tests

Testing:
 - Working Appendix pages
 - Testing each Appendix entry for an existing entry in the Catalog



## Markdown Templating

<details>
 <summary>Obsidian Friendly</summary>

This adaption of the D&D 5E SRD contains optional content designed specifically for PKM applications like Obsidian. [Obsidian.md](https://obsidian.md) is a powerful knowledge base on top of a local folder of plain text Markdown files. That definition sounds simple; however, Obsidian is much, much more. Visit [Josh Plunket's YouTube Channel](https://www.youtube.com/c/JoshPlunkett/videos) to learn more about using Obsidian for your roleplaying game campaign management.

</details>
import React from "react"

import ZoomImage from '../components/ZoomImage';
import TableOfContents from '../components/TableOfContents';

import './about.css';
import Layout from "../components/Layout";
import { HeadProps, Link } from "gatsby";

type DataProps = {
    site: {
      siteMetadata: {
        title: string
      }
    }
  }

export function about() {
    // if(typeof document !== 'undefined'){
    //     document.title = "Complete Compendium - About"
    // }
    return (
        // upper page with category links
    <>
    <Layout url='/about'>
        <div className="about-wrapper">
        <main>
            <h1>About</h1>
            Although called the <i>complete</i> compendium, it is far from complete. Help out on the <a href="https://github.com/decheine/complete-compendium" target="_blank" rel="noopener noreferrer">GitHub</a>. 
            
            <h2 id="quick-links">About Pages</h2>
            <ul>
                <li><Link to="/about/the-monsters">How To Use This "Book"</Link></li>
            </ul>

            <h2 id="summary"> Summary</h2>
            This is a project to create a comprehensive compendium of all the monsters accross the entire Advanced Dungeons and Dragons 2nd Edition collection.
            Advanced Dungeons &amp; Dragons (AD&amp;D) 2nd Edition (AD&D 2e) is a table top roleplaying game created by TSR inc. Thousands of monsters were written over the decades and this website seeks to be a convenient, fair-use way to browse monsters from out of print sourcebooks. 

            <h3 id="motivation"> Motivation </h3>
            <p>
            My friends and I played 2nd edition religiously in high school. I stumbled across a site called lomion.de where someone had created a nearly complete appendix of all ad&d 2nd edition monsters. *All* of them, or so we assumed, that's what it felt like. We loved to use it and explore the vast collection, but the site was quite archaic and barebones in terms of functionality. Unfortunately, the site went down around 2014. However, it was indexed many times by the Wayback machine. So I sought to resurrect the site and bring the complete monstrous compendium of 2nd Edition to life with lots of navigational and explorational features. 
            </p>
            <p>The scope of AD&amp;D content dwarfs all other editions of Dungeons &amp; Dragons. All these monsters serve well as inspriation and starting points, valuable to Game Masters of all fantasy table top roleplaying games. </p>

            <h3 id="purpose"> Purpose </h3>

            <div className="about-body"> 
                <p>
                    This is a project to create a comprehensive compendium of all the monsters accross the 
                    entire Advanced Dungeons and Dragons 2nd Edition collection.
                </p>
                <p>
                    The original creator of this project was <a href="https://web.archive.org/web/20180818101608/http://lomion.de/cmm/_index.php">Lomion</a>, who
                    created a website with a similar goal. Unfortunately, the website is no longer online. It went offline around 2018, but that motivated me to build this.
                </p>
            </div>
            <details>
                <summary>Architecture</summary>
                <p>I started with downloading the entire directory of lomion.de from the Wayback Machine through some command line operations.</p>
                <p>Then with all the mosnter file html documents, I build a harvester program in C++ to collect all the data so that it may be uploaded to a database. The harvester also collected the publicaiton ID numbers of its sourcebook(s), so I can organize the monsters by book. Then the theming of the pages indicates the campaign setting the monster is most prominent, so I can organize the monsters by setting/world. </p>
                <p>I wanted to turn this project into a fully deployed application available for the public. So the next steps were to set up a database to store the monster data; naturally an API is required to publish to and retrieve data form the database. </p>

                <p>
                    This was previously an overengineered mess of cloud compute EC2 instances to run an API and database, and while cool, that isn't what I needed and cost $30/month if I wanted to do it securely.
                    Because of the nature of this data: a load of html files and a campaign setting - book catalog structure, which can be achieved with simple JSON. With publish id's from the monster pages
                    to identify the books, a list of all of the book's titles, authors, and publication years, the catalog can be created. New books can be added to the JSON files easily. New monsters require writing
                    the new monster from an html template and running the harvester program to update the JSON files. I use Gatsby Typescript framework to build statically and host with GitHub pages, so it's free to host 
                    except for the domain, which is still cheap.
                </p>
                <p>

                </p>
            </details>
            

            <h2 className="atx" id="features">Features</h2>
            <h3 className="atx" id="appendix">Appendix</h3>
            <p>A comprehensive list of all the monsters on a single page. This page simply lists all monster titles and links them with their corresponding monster key. </p>
            <h3 className="atx" id="catalog">Catalog</h3>
            <p>Here you can browse through all of the books and sources that contain monsters. You can also browse by campaign settting/world. </p>
            <h3 className="atx" id="search">Search</h3>
            <p>
                Implemented basic text filtering in the appendix page, now searchable!
            </p>
            
            <h2 className="atx" id="future">Future</h2>
            <h3 className="atx" id="planned-features">Planned Features</h3>
            <h4 className="atx" id="priority">Priority</h4>
            <p>List of features that I intend to implement and add to the site.</p>
            <ul>
            <li><s>Pivot "database" to static site generation with json files and host for free</s></li>
            <li>Add a table of contents to the Appendix</li>
            <li>Add the "How to Use this Book" / "The Monsters" page. Have each <code>MonsterPage</code> link to this page too.</li>
            <li><s>Automate the missing data reporting process.</s> Now organized through GitHub issues.</li>
            </ul>
            <h4 className="atx" id="stretch-goals">Stretch Goals</h4>
            <ul>
            <li>Appendix Title Redudancy mode. Switch that toggles on/off Redudancy mode, which displays all aliases of all monsters. Take caution when doing this since there are over 7000 titles and this page will not perform well on lower-spec devices. Warning will be placed next to it. Maybe React detects if device can support it and will hide the option entirely if it detects a lower spec device. </li>
            <li>Lore:<ul>
            <li>Baatezu Promotion and Demotion</li>
            <li>The Comlete Golem Table</li>
            <li>The Planes of Existence</li>
            </ul>
            </li>
            <li>Pages:<ul>
            <li>Similar Monster page like a Monstrous Classification Page</li>
            </ul>
            </li>
            <li>Glossary for terms</li>
            <li>Complete Spell Description list so you can hover over spells and see what they do.</li>
            </ul>



        </main>
        <TableOfContents/>
        </div>
    </Layout>
            
    </>

        // lower page with all book list
    );
}

export default about;

export function Head(props: HeadProps<DataProps>) {
    return (
      <>
      <title>About - AD&D 2e Complete Compendium</title>
      
      </>
    )
  }
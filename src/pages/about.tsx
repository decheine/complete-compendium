import React from "react"

import ZoomImage from '../components/ZoomImage';
import TableOfContents from '../components/TableOfContents';

import './about.css';
import Layout from "../components/Layout";
import { HeadProps } from "gatsby";

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
            

            
            <h2 id="summary"> Summary</h2>
            What is Advanced Dungeons &amp; Dragons:  Advanced Dungeons &amp; Dragons (AD&amp;D) 2nd Edition is a table top roleplaying game published by TSR inc. Over the decades of its life, hundreds of products were published for AD&amp;D 2nd Edition, and with them, thousands of monsters. This website is a compendium of all of the monsters across all of the books published for AD&amp;D 2nd Edition.

            <h3 id="motivation"> Motivation </h3>
            <p>
            My friends and I played 2nd edition religiously in high school. I stumbled across a site called lomion.de where someone had created a complete appendix of all ad&d 2nd edition monsters. *All* of them. We love to use it and explore the vast collection, but the site was quite archaic and barebones in terms of functionality. Unfortunately, the site went down around 2014. However, it was indexed many times by the Wayback machine. So I sought to resurrect the site and bring the complete monstrous compendium of 2nd Edition to life with lots of navigational and explorational features. 
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
            <h2 id="architecture"> Architecture</h2>
            <p>Started with downloading the entire directory of lomion.de from the Wayback Machine through some command line operations.</p>
            <p>Then with all the mosnter file html documents, I build a harvester program in C++ to collect all the data so that it may be uploaded to a database. The harvester also collected the publicaiton ID numbers of its sourcebook(s), so I can organize the monsters by book. Then the theming of the pages indicates the campaign setting the monster is most prominent, so I can organize the monsters by setting/world. </p>
            <p>I wanted to turn this project into a fully deployed application available for the public. So the next steps were to set up a database to store the monster data; naturally an API is required to publish to and retrieve data form the database. </p>

            import React from "react"            <input type="checkbox" id="ZoomImage" className="zoomcheck"/>
            <label htmlFor="ZoomImage">
                <ZoomImage src="/images/full_architecture.png" alt="A flowchart of the entire website"/>
            </label>

            <p>I chose PostgreSQL over other database platforms due to its rich toolset, but mainly support for Arrays and built in indexing and lookup system so searches can be done natively by the database.</p>
            <p>For the API I wanted something simple but scalable if I wanted. So I chose NodeJS with Express as the web framework and Sequelize to communicate with the Database. I figured these two services could be hosted on AWS EC2 instances, I do not anticipate sustained high traffic but the workload isn't heavy so even the smallest EC2 could support a few users making requests at once.</p>
            <p>Now for the Continuous Deployment and Integration. I wanted the cheapest, most streamlined way to harvest monster data when more data is collected. I chose to use GitHub Actions to run a Docker container running the harvester. GitHub Actions then publishes the latest data via the API. Authentication is done by requesting AWS permissions for the IP of the GitHub Actions runner and then requesting to remove them after publication is finished. </p>
            <p>For the frontend application I chose React for its statefulness, hooks, and option for whatever complexity I would want in the future. This React application is hosted on GitHub pages, which is a low price if the repo is private and free if it is public. I want to keep this public, in order to do so I'll need to find a way of obfuscating the API endpoint IP.</p>
            <p>For CI/CD for the API, the EC2 instance running it is set at a remote for the repository, so when new tags are published, the changes get pushed to the remote server and the server is updated automatically. </p>
            <p>Thus the entire pipeline should be online continuously and I am free to upgrade each of the pieces, </p>

            <h2 className="atx" id="features">Features</h2>
            <h3 className="atx" id="appendix">Appendix</h3>
            <p>A comprehensive list of all the monsters on a single page. This page simply lists all monster titles and links them with their corresponding monster key. </p>
            <h3 className="atx" id="catalog">Catalog</h3>
            <p>Here you can browse through all of the books and sources that contain monsters. You can also browse by campaign settting/world. </p>
            <h3 className="atx" id="search">Search</h3>
            <p>Implemented a simple lookup of the database for monsters based on lexemes in each of the monsters multiple titles. Of course, CTRL + F  on the Appendix page works just fine as well. </p>
            <h2 className="atx" id="future">Future</h2>
            <h3 className="atx" id="planned-features">Planned Features</h3>
            <h4 className="atx" id="priority">Priority</h4>
            <p>List of features that I intend to implement and add to the site.</p>
            <ul>
            <li>Format this About page better</li>
            <li>Add the "How to Use this Book" / "The Monsters" page. Have each <code>MonsterPage</code> link to this page too.</li>
            <li>Implement more robust and streamlined caching of resources fetched with API. </li>
            <li>Appendix Title Redudancy mode. Switch that toggles on/off Redudancy mode, which displays all aliases of all monsters. Take caution when doing this since there are over 7000 titles and this page will not perform well on lower-spec devices. Warning will be placed next to it. Maybe React detects if device can support it and will hide the option entirely if it detects a lower spec device. </li>
            <li>Add a table of contents to the Appendix</li>
            <li>Automate the missing data reporting process. Store missing data reports in the database, create some simple format for me to enter a new "report". Probably just a csv file with fields like "monster_key", "report description", "known source"</li>
            </ul>
            <h4 className="atx" id="stretch-goals">Stretch Goals</h4>
            <ul>
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
            <h3 className="atx" id="changelog">Changelog</h3>
            <ul>
            <li>Start with Version v1.0. Look into changelog format</li>
            </ul>
            <h2 className="atx" id="monster-data-to-do">Monster Data To-Do</h2>
            <p>Running list of bugs, errors, missing data, and other tasks that need to be done to complete the Compendium.</p>
            <h3 className="atx" id="need-to-be-added">Need to be added</h3>
            <table>
            <thead>
            <tr>
            <th>Monster</th>
            <th>Filename</th>
            <th>Source #</th>
            </tr>
            </thead>
            <tbody><tr>
            <td>The Queen of Chaos</td>
            <td>queofcha.php</td>
            <td>1145 pg 204</td>
            </tr>
            <tr>
            <td>Triphegs</td>
            <td>triphegs.php</td>
            <td></td>
            </tr>
            <tr>
            <td>Wild Hunt</td>
            <td>wildhunt.php</td>
            <td>birthrite 3140?</td>
            </tr>
            <tr>
            <td>Miska the Wolf-spider</td>
            <td>wospmisk.php</td>
            <td>planescape</td>
            </tr>
            <tr>
            <td>Elven horse</td>
            <td>yyllethy.php</td>
            <td>dragon magazine 269</td>
            </tr>
            <tr>
            <td></td>
            <td></td>
            <td></td>
            </tr>
            <tr>
            <td></td>
            <td></td>
            <td></td>
            </tr>
            <tr>
            <td></td>
            <td></td>
            <td></td>
            </tr>
            <tr>
            <td></td>
            <td></td>
            <td></td>
            </tr>
            </tbody></table>
            <h3 className="atx" id="missing-information">Missing Information</h3>
            <table>
            <thead>
            <tr>
            <th>Monster</th>
            <th>Filename</th>
            <th>Missing</th>
            <th>Source</th>
            </tr>
            </thead>
            <tbody><tr>
            <td>Aboleth</td>
            <td>aboleth.html</td>
            <td>Ecology Section</td>
            <td>2140 pg 6</td>
            </tr>
            <tr>
            <td>Angler Fish</td>
            <td></td>
            <td></td>
            <td></td>
            </tr>
            <tr>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            </tr>
            <tr>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            </tr>
            </tbody></table>
            <h3 className="atx" id="broken-pages">Broken Pages</h3>
            <table>
            <thead>
            <tr>
            <th>Monster</th>
            <th>Filename</th>
            <th>Missing</th>
            <th>Source</th>
            </tr>
            </thead>
            <tbody><tr>
            <td>Mammal, Minimal</td>
            <td>mammmini</td>
            <td></td>
            <td>2103</td>
            </tr>
            <tr>
            <td>Chaos elemental fire/water</td>
            <td></td>
            <td>needs better image</td>
            <td></td>
            </tr>
            <tr>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            </tr>
            </tbody></table>
            <h3 className="atx" id="strange-monsters">Strange Monsters</h3>
            <table>
            <thead>
            <tr>
            <th>Monster</th>
            <th>Filename</th>
            <th>Note</th>
            </tr>
            </thead>
            <tbody><tr>
            <td>Moldling</td>
            <td>moldling</td>
            <td>Source listed as "The Lonesome Road, Shawn Mulder". Must find true origin. Could be Die Vecna Die</td>
            </tr>
            <tr>
            <td></td>
            <td></td>
            <td></td>
            </tr>
            <tr>
            <td></td>
            <td></td>
            <td></td>
            </tr>
            </tbody></table>
            <h3 className="atx" id="missing-books">Missing Books</h3>
            <ul>
            <li>I, Tyrant</li>
            <li>Alternity?</li>
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
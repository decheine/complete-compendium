import * as React from "react"
import { graphql, HeadProps, HeadFC, PageProps, Link } from "gatsby"

import * as homeStyle from '@styles/modules/home.module.css'
import CSS from 'csstype';

import "./home.css";
import "../styles/global.css"

import Navbar from "../components/Navbar"
import Footer from "../components/Footer";
import RandomMonsterButton from "../components/RandomMonsterButton";
import { Cards } from "../components/Cards";
import { StatisticBlock } from "../components/Statistics";
import { StaticImage } from "gatsby-plugin-image"

import { SEO } from "../components/SEO";
import { GatsbyImage } from "gatsby-plugin-image";


/////////////////////////
// Gatsby Stuff
type DataProps = {
  site: {
    siteMetadata: {
      title: string
    }
  }
}

const randomButtonStyle: CSS.Properties = {
  marginBlockStart: "unset",
  marginBlockEnd: "unset",
  marginInlineStart: "unset",
  marginInlineEnd: "unset",

  /* Monstrous Title 3 */
  position: "relative",
  fontFamily: "Leksa Sans DemiBold",
  fontStyle: "normal",
  fontWeight: 600,
  fontSize: "24px",
  display: "flex",
  alignItems: "center",
  textAlign: "center",
  textDecoration: "none",
  textTransform: "capitalize",
  color: "white",
  

  paddingTop: "1rem",
  paddingBottom: "1rem",
  paddingLeft: "2rem",
  paddingRight: "2rem",
  zIndex: 1,
}

const bookListStyle: CSS.Properties = {
  display: "flex",
  flexWrap: "wrap",
  justifyContent: "space-evenly"
}

const IndexPage: React.FC<PageProps> = () => {
  return (
    <main>
      
      {/* <link rel="stylesheet" href="https://use.typekit.net/som5rdn.css"></link> */}
      <>
          <Navbar/>
            <div className={homeStyle.home}>
              {/* Hero */}
              <div className={homeStyle.heroContainer}>
                <div className='image-container'>
                  <picture>
                    <StaticImage src="../images/paper.webp" alt="Soft gray paper texture background." /> 
                    <img className='hero-img' src="/images/paper.webp" alt="Soft gray paper texture background." />
                    <img className='hero-img-hidden' src="/opengraph_banner.webp" alt="A menagery of monsters from across the lands of Dungeons & Dragons together on a white background." />
                  </picture>
                </div>
                
                <h1 className={homeStyle.adnd}>Advanced Dungeons & Dragons 2nd Edition</h1>
                <h2>Complete Monstrous <br/>Compendium</h2>

                {/* Random Monster Button */}
                <div className={homeStyle.random_monster_button_wrapper}>
                {/* <div className="random_monster_button"> */}
                    {/* <RandomMonsterButton randomButtonStyle={randomButtonStyle} /> */}
                    <RandomMonsterButton home={true} />
                </div>

              </div>

              {/* <div className="hero_tsr">
              <img src="images/tsr.png" height="150px" alt="TSR logo"></img>
              </div> */}
              <Cards />

              {/* Needs to be redone */}
              <StatisticBlock />

              <div className="summary">
                <div className="summary_banner_container">
                  <div className="summary_text">
                    <p className="summary_par">
                      Complete* browsable, searchable appendix of EVERY monster, sourcebook, manual, and campaign setting in Advanced Dungeons & Dragons 2nd Edition. An ongoing effort to fully catalog and index every monster from AD&D 2nd edition, there is still much work to be done. With missing images, bad unicode characters, and missing information, I have my work cut out for me. The next phase will involve scanning the source data for errors and displaying this on the <Link to="/about">About</Link> page.
                    </p>
                    <p className="summary_par">
            
                    Welcome to the Complete Compendium! A work in progress, this compendium seeks to archive and catalogue every monster from Advanced Dungeons & Dragons, 2nd Edition. Not just monsters from the core books, not just from monstrous compendiums.  Every. Monster. Across all sources, magazines, and settings. Go to the Index for a full (and redundant) list of monster names and links to their pages, or check out the Catalogue for a more browsable experience. 
                    </p>
                    <p className="summary_par">
                    This website has resurrected the efforts of an another, the creator of lomion.de, archived by the wayback machine. I coded an extractor for harvesting monster data from all these files and putting it into a database. Read more about my process on the About page.
                    </p>
                  </div>
                </div>
              </div>
            </div>
          <Footer />
        </>
    </main>
  )
}

export default IndexPage

// export const Head: HeadFC = () => <title>Home Page</title>
export function Head(props: HeadProps<DataProps>) {
  return (
    <>
    <script src="https://kit.fontawesome.com/c6a77c0087.js" crossOrigin="anonymous"></script>
    <title>{props.data.site.siteMetadata.title}</title>
    <SEO />
    </>
  )
}

export const query = graphql`
  {
    site {
      siteMetadata {
        title
      }
    }
  }
`

import React from "react"
import Layout from '../components/Layout';
import {  PageProps, Link, graphql, HeadFC  } from "gatsby";

import { CreatePagesArgs } from 'gatsby';
import { Interweave } from "interweave";

// Formatting
import "@styles/SettingColors.css"
import COLORS from '@styles/SettingColors'
import RandomMonsterButton from "@components/RandomMonsterButton";

import * as monsterPageStyles from "@styles/modules/monsterpage.module.css"

import { polyfill } from 'interweave-ssr';

polyfill();
// export default function Container({ children }) {
//   return <div className={containerStyles.container}>{children}</div>
// }
// const isBrowser = typeof window !== "undefined"

const cat_acronyms = require('@data/CatAcronyms.json')
// const sorted_tsr = require('@data/sortedtsr.json')
const all_tsr = require('../../data/all_tsr.json')
const publishId_to_acronym = require('@data/publishId_to_acronym.json')
///////////
// Styles

const settingImageStyle = {
  float: "right",
  width: "150px",
}

const headingStyles = {
  marginTop: 0,
  marginBottom: 64,
  maxWidth: 320,
}

type MonsterDataType = {
    TSR: string[],
    fullBody: string,
    images: string[],
    setting: string,
    statblock: Object,
    title: string
}

type MonsterPageContext = {
    monster_key: string
    monster_data: MonsterDataType
    sources: string[]
    statblock_names: string[]
    title: string
    prev_key: string
    next_key: string
    catelog_book: string
    catelog_setting: string
    monster_path: string
}


type MonsterDataWrapper = {
    monster_page: MonsterPageContext
    // workaround syntax warning fix,
    // the following aren't used in reality, only
    // monster_page
    monster_key: string
    monster_data: MonsterDataType
    sources: string[]
    statblock_names: string[]
    title: string
    prev_key: string
    next_key: string
    catelog_book: string
    catelog_setting: string
    
}

interface Props {
  pageContext: MonsterPageContext
  }

const BookMonsterTemplate: React.FC<Props> = ({pageContext }) => {
//   const [screenSize, setScreenSize] = useState(getCurrentDimension());

//   function getCurrentDimension(){
//     if(isBrowser){

//       return {
//         width: global.window.innerWidth,
//       	height: global.window.innerHeight
//       }
//     } else {
//       return {
//         width: 0,
//         height: 0,
//       }
//     }
// }

//   useEffect(() => {
//     const updateDimension = () => {
//       setScreenSize(getCurrentDimension())
//     }
//     if(isBrowser)
//       global.window.addEventListener('resize', updateDimension);
    
//     return(() => {
//         global.window.removeEventListener('resize', updateDimension);
//     })
//   }, [screenSize])

  const monster_page_data: MonsterPageContext = pageContext
  // const monster_object = pageContext.monster_object
//   console.log("monster page")
//   console.log(monster_page_data)
  // console.log("monster template")
  // console.log(monster_object)
  const monster_key = monster_page_data.monster_key
  const title = monster_page_data.title
  const sources = monster_page_data.sources
  const previous_monster_key = (typeof monster_page_data.prev_key !== "undefined") ? monster_page_data.prev_key : monster_key; 
  const next_monster_key = (typeof monster_page_data.next_key !== "undefined") ? monster_page_data.next_key : monster_key;  
  const catelog_book = monster_page_data.catelog_book
  const catelog_setting = monster_page_data.catelog_setting
//   console.log(previous_monster_key, next_monster_key)
  // Checking Main Image
  //  If the regex pattern matches, know we NEED an image. So set the url to where it should be with monster_key
  //  and also have an onerror="javascript:this.src='images/default.jpg'" to set the image to default if it doesn't exist
  //  If doesn't need image, set the bool flag and no image will be rendered
  let monster_image = <></>;
  let needs_image = true;
  let image_url = "";
  // if(monster_page_data.monster_data.images[1]) regex contains monster_key
  let main_img_pattern = "img/" + monster_page_data.monster_key
  if(monster_page_data.monster_data.images[1] && monster_page_data.monster_data.images[1].match(new RegExp(main_img_pattern, "g"))){
      // console.log("Should have image")
      needs_image = true;
  } else {
      // console.log("Does not have image")
      needs_image = false;
  }

  if(needs_image){
      // Set image url
      image_url = "/images/monsters/img/" + monster_page_data.monster_key + ".gif"
      let image_placeholder = "https://upload.wikimedia.org/wikipedia/commons/6/65/No-Image-Placeholder.svg"

      monster_image = <img className={monsterPageStyles.monsterImage}   src={image_url}
      alt={monster_page_data.monster_data.title} 
      title={monster_page_data.monster_data.title} 
      onError={({currentTarget}) => {
          currentTarget.onerror = null;
          currentTarget.alt = "This monster is missing it's image. It will be found eventually.";
          currentTarget.src = image_placeholder;
          currentTarget.title = "Missing image of " + monster_page_data.monster_data.title;
      }}/>

  } 
    
  // Change document title to monster title
  // if(typeof document !== 'undefined'){
  //     document.title = monster_page_data.monster_data.title + " - Complete Compendium";
  // }

  // Handle setting and accent color.
  const setting_name = monster_page_data.monster_data.setting;
  const setting_acr = cat_acronyms[setting_name]
  var hrClass = "hr2"
  var titleStyle = {}
  if(setting_acr){
      hrClass = "hr2-" + setting_acr
      const colorVar = "--color-" + setting_acr
      titleStyle = {color: COLORS.get(setting_acr)}
  }

  
  let monsterNavWidgets: JSX.Element = <div>
  <div className={monsterPageStyles.monsterNavLinks}>
    <div className={monsterPageStyles.pageRandomMonsterButton}>
      <RandomMonsterButton home={false} />
    </div>
    <div className={monsterPageStyles.horizontalMonsterLinks}>
      <Link className={monsterPageStyles.monsterNavLink} to={"../" + previous_monster_key}>
        <div className={monsterPageStyles.monsterNav}>
            Previous
        </div>
      </Link>
      {/* Random Monster */}
      {/* <div className={monsterPageStyles.monsterNav}>
          <RandomMonsterButton />
        </div> */}
      <Link className={monsterPageStyles.monsterNavLink} to={"../" + next_monster_key}>
        <div className={monsterPageStyles.monsterNav}>
          Next
        </div>
      </Link>
    </div>
  </div>
</div>

  // Title style

  
  if(monster_key == "horax"){
    console.log("booktemplate monster, HORAX")
    console.log("prev", previous_monster_key)
    console.log("next", next_monster_key)
  }
  const fullBody = monster_page_data.monster_data.fullBody;
  const interweaveMonsterBody: JSX.Element = <div className="set-html" dangerouslySetInnerHTML={{__html: fullBody}} />

  // const { book_data } = data
  return (
    <Layout url={`/catalog/${catelog_setting}/${catelog_book}/${monster_key}`}>
      <div>
        {monsterNavWidgets}

      {/* TITLE and SETTING */}
      <div className={monsterPageStyles.topHeader}>
          <h1 style={titleStyle}>{monster_page_data.monster_data.title}</h1>
          {
          cat_acronyms[monster_page_data.monster_data.setting] != "al" ?
          <Link to={"/catalog/" + cat_acronyms[monster_page_data.monster_data.setting]}>
              <img className={monsterPageStyles.settingImage} src={`/img_settings/${cat_acronyms[monster_page_data.monster_data.setting]}.gif`}  alt={monster_page_data.monster_data.setting + "Campaign Setting Logo"} title={monster_page_data.monster_data.setting}/>
          </Link>
          :
            <img className={monsterPageStyles.settingImage} src={`/img_settings/${cat_acronyms[monster_page_data.monster_data.setting]}.gif`}  alt={monster_page_data.monster_data.setting + "Setting Logo"} title={monster_page_data.monster_data.setting}/>
          }
      </div>
      
      <hr className ={hrClass}/>
      <hr className ={monsterPageStyles.hr1}/>

      <div className={monsterPageStyles.monsterImgFrame}>
      {monster_image}
      </div>

      <Interweave className="interweave" content={fullBody} />
      {/* {interweaveMonsterBody} */}

      {/* TSR Array */}
      <div className={monsterPageStyles.sourceList}>
        <div className={monsterPageStyles.tsrLabel}>
            Sourcebooks:
        </div>
        <div className={monsterPageStyles.tsr}>
            {
                (monster_page_data.monster_data.hasOwnProperty("TSR") && monster_page_data.monster_data["TSR"] != null) ?
                    monster_page_data.monster_data["TSR"].map((tsr: string) => {
                        return (
                            <div key={tsr}>
                                <Link to={"/catalog/" + publishId_to_acronym[tsr] + "/" + tsr}>{all_tsr[tsr]?.title} ({tsr})</Link>
                                <br/>
                            </div>
                        )
                    }
                )
                : "No TSR"
            }
        </div>
    </div>

    {/* LAST MODIFIED */}
    {/* <div className="last-modified">
        Last Modified: {monster_page_data.updatedAt}
    </div> */}
    <div className={monsterPageStyles.printLink}>
      <Link to={`/appendix/${monster_key}/print`}>Print-friendly page</Link> (Experimental)
    </div>



      </div>
    </Layout>
  )
}

export const Head: React.FC<Props> = ({ pageContext }) => (
  <>
    <title>{pageContext.title + " - AD&D Complete Compendium"}</title>
    <meta property="og:site_name" content="AD&D 2nd Edition Complete Monstrous Compendium"/>
    <meta property="og:title" content={pageContext.monster_data.title  + " | AD&D Complete Compendium"}/>
    <meta property="og:url" content={"https://www.completecompendium.com" + pageContext.monster_path}/>
    <meta property="og:type" content="website"/>
    {
      pageContext.monster_data.images[1] && pageContext.monster_data.images[1].match(new RegExp(pageContext.monster_key, "g")) ?
      <>
      <meta property="og:image" content={"https://www.completecompendium.com/images/monsters/img/" + pageContext.monster_key + ".gif"}/>
      <meta name="twitter:image" content={"https://www.completecompendium.com/images/monsters/img/" + pageContext.monster_key + ".gif"}/>
    </>
      :
      <></>
    }
    <meta property="og:image:width" content="300"/>
    <meta property="og:image:height" content="360"/>
    
          
    {/* <meta name="description" content={ getMonsterDescription(pageContext.monster_key ,pageContext.monster_data.fullBody) } /> */}
    {/* Image: "/images/monsters/img/" + monster_page_data.monster_key + ".gif" */}
    <meta name="twitter:card" content="summary_large_image"/>
    <meta name="twitter:url" content={"https://www.completecompendium.com" + pageContext.monster_path} />
    <meta name="twitter:title" content="Advanced Dungeons & Dragons 2nd Edition Complete Compendium" />
        
  </>
)


export default BookMonsterTemplate
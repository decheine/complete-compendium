import React from "react"
// import { useEffect, useState } from 'react'

import Layout from '../components/Layout';
import {  PageProps, Link, HeadFC, HeadProps, graphql  } from "gatsby";

import { CreatePagesArgs } from 'gatsby';
import { Interweave } from "interweave";

// Formatting
import "@styles/SettingColors.css"
import COLORS from '@styles/SettingColors'
// import RandomMonsterButton from "@components/RandomMonsterButton";

import * as monsterPageStyles from "@styles/modules/monsterprintpage.module.css"
import "@styles/modules/monsterprintpage.module.css"

import getMonsterDescription from "@components/regex_description"
import { polyfill } from 'interweave-ssr';

polyfill();
// const isBrowser = typeof window !== "undefined"

const cat_acronyms = require('@data/CatAcronyms.json')
// const sorted_tsr = require('@data/sortedtsr.json')
const publishId_to_acronym = require('@data/publishId_to_acronym.json')

const all_tsr = require('../../data/all_tsr.json')
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
    monster_path: string
    // intereweave_body: JSX.Element
}

interface Props {
  pageContext: MonsterPageContext
  }




const PrintMonsterTemplate: React.FC<Props> = ( {pageContext} ) => {

  const monster_page_data: MonsterPageContext = pageContext
  const monster_key = monster_page_data.monster_key
  const title = monster_page_data.title
  const sources = monster_page_data.sources
  const previous_monster_key = monster_page_data.prev_key
  const next_monster_key = monster_page_data.next_key
  const fullBody = monster_page_data.monster_data.fullBody;

  let monster_image = <></>;
  let needs_image = true;
  let image_url = "";
  // if(monster_page_data.monster_data.images[1]) regex contains monster_key
  let main_img_pattern = "img/" + monster_page_data.monster_key
  if(monster_page_data.monster_data.images[1] && monster_page_data.monster_data.images[1].match(new RegExp(main_img_pattern, "g"))){
      needs_image = true;
  } else {
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

  return (
    <>
      <div className="print" >
      {/* TITLE */}
      <article>
      <div className={monsterPageStyles.topHeader}>
          <h1 style={titleStyle}>{monster_page_data.monster_data.title}</h1>
          <Link to={"/catalog/" + cat_acronyms[monster_page_data.monster_data.setting]}>
              <img className={monsterPageStyles.settingImage} src={`/img_settings/${cat_acronyms[monster_page_data.monster_data.setting]}.gif`}  alt={monster_page_data.monster_data.setting + "Campaign Setting Logo"} title={monster_page_data.monster_data.setting}/>
          </Link>
      </div>
      
      <hr className ={monsterPageStyles.hr1}/>
      <hr className ={hrClass}/>

    <div className={monsterPageStyles.columnWrapper}>
      <div className={monsterPageStyles.monsterImgFrame}>      
      {monster_image}
      {/* IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE IMAGE  */}
      </div>
      <Interweave className="interweave" content={fullBody} />
      </div>
    </article>
      {/* {interweaveMonsterBody} */}

      {/* <Interweave content="This string contains <b>HTML</b> and will safely be rendered!" /> */}
      {/* {test_jsx} */}
      {/* TSR Array */}
      <div className={monsterPageStyles.sourceList}>
        <div className={monsterPageStyles.tsrLabel}>
        </div>
        <div className={monsterPageStyles.tsr}>
            {
                (monster_page_data.monster_data.hasOwnProperty("TSR") && monster_page_data.monster_data["TSR"] != null) ?
                    monster_page_data.monster_data["TSR"].map((tsr: string) => {
                        return (
                            <div key={tsr} className={monsterPageStyles.source}>
                                {all_tsr[tsr]?.title} ({tsr})
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




      </div>
    </>
  )
}

// interface HeadProps {
//   location: any,
//   params: any,
//   data: any,
//   pageContext: MonsterPageContext
// }



// export function Head ({ location, params, data, pageContext }: HeadProps) => (
//   <>
//     <title>{pageContext.title}</title>
//     <meta name="description" content={data.page.description} />
//     <meta
//       name="twitter:url"
//       content={`https://www.foobar.tld/${location.pathname}`}
//     />
//   </>
// )

// export function Head(props: HeadProps<DataProps>){

//   // Extract description.

//   // Demo description for now.

//   const monster_desc = `Description for ${props.data.sitePage.pageContext.title}`
//   console.log("Head", props.data.sitePage.pageContext)

//   return (
//     <>
//       <title>{props.data.sitePage.pageContext.title}</title>
//       <meta name="description" content={monster_desc} />
//     </>
//   )
// }



// export const Head = () => (
//   <>
//     <title>Hello World</title>
//     <meta name="description" content="Hello World" />
//   </>
// )

// Function that takes in a fullBody string and 
// returns the monster description (first paragraph) 
//  



export const Head: React.FC<Props> = ({ pageContext }) => (
  <> 
  </>
)

export default PrintMonsterTemplate

export const query = graphql`
  {
    sitePage {
      pageContext
    }
  }
`
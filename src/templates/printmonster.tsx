import React from "react"
// import { useEffect, useState } from 'react'

import Layout from '../components/Layout';
import { PageProps, Link, HeadFC, HeadProps, graphql } from "gatsby";

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




const PrintMonsterTemplate: React.FC<Props> = ({ pageContext }) => {

  const monster_page_data: MonsterPageContext = pageContext
  const monster_key = monster_page_data.monster_key
  const title = monster_page_data.title
  const sources = monster_page_data.sources
  const previous_monster_key = monster_page_data.prev_key
  const next_monster_key = monster_page_data.next_key
  let fullBody = monster_page_data.monster_data.fullBody;

  let monster_image = <></>;
  let needs_image = true;
  let image_url = "";
  // if(monster_page_data.monster_data.images[1]) regex contains monster_key
  let main_img_pattern = "img/" + monster_page_data.monster_key
  if (monster_page_data.monster_data.images[1] && monster_page_data.monster_data.images[1].match(new RegExp(main_img_pattern, "g"))) {
    needs_image = true;
  } else {
    needs_image = false;
  }

  if (needs_image) {
    // Set image url
    image_url = "/images/monsters/img/" + monster_page_data.monster_key + ".gif"
    let image_placeholder = "https://upload.wikimedia.org/wikipedia/commons/6/65/No-Image-Placeholder.svg"

    monster_image = 
    <div className={monsterPageStyles.monsterImgFrame}>
    <img className={monsterPageStyles.monsterImage} src={image_url}
      alt={monster_page_data.monster_data.title}
      title={monster_page_data.monster_data.title}
      onError={({ currentTarget }) => {
        currentTarget.onerror = null;
        currentTarget.alt = "This monster is missing it's image. It will be found eventually.";
        currentTarget.src = image_placeholder;
        currentTarget.title = "Missing image of " + monster_page_data.monster_data.title;
      }} /></div>
  } else {
    // Handle Statblock column span if there is no image.
    fullBody = fullBody.slice(0,9) + " style=\"column-span: all;\"" + fullBody.slice(9);

  }

  // Handle setting and accent color.
  const setting_name = monster_page_data.monster_data.setting;
  const setting_acr = cat_acronyms[setting_name]
  var hrClass = "hr2"
  var titleStyle = {}
  if (setting_acr) {
    hrClass = "hr2-" + setting_acr
    const colorVar = "--color-" + setting_acr
    titleStyle = { color: COLORS.get(setting_acr) }
  }



  return (
    <>
      <div className="print" >
        {/* TITLE */}
        <div className={monsterPageStyles.topHeader}>
          <div className={monsterPageStyles.topHeaderInner}>
            <h1 style={titleStyle}>{monster_page_data.monster_data.title}</h1>
            <div className={monsterPageStyles.tsrPrint}>
                {
                  (monster_page_data.monster_data.hasOwnProperty("TSR") && monster_page_data.monster_data["TSR"] != null) ?
                    monster_page_data.monster_data["TSR"].map((tsr: string) => {
                      return (
                        <div key={tsr} className={monsterPageStyles.source}>
                          {tsr}
                          <br />
                        </div>
                      )
                    }
                    ) : "No TSR"
                }
              </div>
            {
              cat_acronyms[monster_page_data.monster_data.setting] != "al" ?
              <Link to={"/catalog/" + cat_acronyms[monster_page_data.monster_data.setting]}>
                  <img className={monsterPageStyles.settingImage} src={`/img_settings/${cat_acronyms[monster_page_data.monster_data.setting]}.gif`}  alt={monster_page_data.monster_data.setting + "Campaign Setting Logo"} title={monster_page_data.monster_data.setting}/>
              </Link>
              :
                <img className={monsterPageStyles.settingImage} src={`/img_settings/${cat_acronyms[monster_page_data.monster_data.setting]}.gif`}  alt={monster_page_data.monster_data.setting + "Setting Logo"} title={monster_page_data.monster_data.setting}/>
            }
          </div>
          <hr className={monsterPageStyles.hr1} />
          <hr className={hrClass} />

        </div>
        <article>


          <div className={monsterPageStyles.columnWrapper}>
            {monster_image}
            <Interweave className="interweave" content={fullBody} />
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
                          <br />
                        </div>
                      )
                    }
                    ) : "No TSR"
                }
              </div>
            </div>

          </div>
        </article>
        {/* LAST MODIFIED */}
        {/* <div className="last-modified">
        Last Modified: {monster_page_data.updatedAt}
    </div> */}




      </div>
    </>
  )
}

export const Head: React.FC<Props> = ({ pageContext }) => (
  <>
    <title>{pageContext.title}</title>
    <meta property="og:site_name" content="AD&D 2nd Edition Complete Monstrous Compendium"/>
    <meta property="og:title" content={pageContext.monster_data.title}/>
    <meta property="og:description" content={ getMonsterDescription(pageContext.monster_key ,pageContext.monster_data.fullBody) }/>
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
    <meta name="twitter:description" content={ getMonsterDescription(pageContext.monster_key ,pageContext.monster_data.fullBody) } />
        
  </>
)



// export const Head: React.FC<Props> = ({ pageContext }) => (
//   <>
//   </>
// )

export default PrintMonsterTemplate

export const query = graphql`
  {
    sitePage {
      pageContext
    }
  }
`
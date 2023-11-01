

import React from "react";

import Layout from "@components/Layout";
// import * as settingStyles from "@styles/modules/settings.module.css"

import { BookList } from "@components/BookList";
// import './SettingPage.css'
const ACRONYMS = require('@data/CatAcronyms.json')
const AcronymToSetting = require('@data/AcronymsSetting.json')

// Input Structure
interface CategoryProps {
    category: string
}

const settingImgStyle = {
    display: "flex",
    width: "fit-content",
    alignContent: "center",
    alignItems: "center",
    justifyContent: "center",
    marginLeft: "auto",
    marginRight: "auto",
    marginBottom: "3em",
}

const headerImgStyle = {
    width: "100%"
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
}


type SettingDataWrapper = {
    category: string
    // workaround syntax warning fix,
    // the following aren't used in reality, only
    // monster_page
    // books: string[]
}

interface Props {
    pageContext: SettingDataWrapper
  }



const SettingTemplate: React.FC<Props> = ({ pageContext }) => {
    // const the_category = props.category;
    if(pageContext.category === undefined){
        console.log("category undefined")
        return (
            <>
            </>
        )
    } else {
        // console.log("setting acronym: ", pageContext.category)
        return (
            <>
                <Layout url={`/catalog/${pageContext.category}`}>

                    {/* <div className={settingStyles.settingLogo}> */}
                    <div style={settingImgStyle}>
                        <img style={headerImgStyle} src={'/images/grf/' +  pageContext.category + '.gif'} alt={AcronymToSetting[pageContext.category] + 'category image'}></img>

                    </div>
                    
                    <BookList category={pageContext.category}/>
                </Layout>
            </>
        )
        
    }
}

export const Head: React.FC<Props> = ({ pageContext }) => (
    <>
      <title>{AcronymToSetting[pageContext.category]} - AD&D Complete Compendium</title>
      <meta property="og:site_name" content="AD&D 2nd Edition Complete Monstrous Compendium"/>
      <meta property="og:title" content={AcronymToSetting[pageContext.category]  + " | AD&D Complete Compendium"}/>
      <meta property="og:description" content={ "Catalog page, for the " + AcronymToSetting[pageContext.category] + "campaign settings" }/>
      <meta property="og:url" content={"https://www.completecompendium.com" + '/Catalog/' +  pageContext.category}/>
      <meta property="og:type" content="website"/>
      {
        <>
        <meta property="og:image" content={"https://www.completecompendium.com" + '/images/grf/' +  pageContext.category + '.gif'}/>
        <meta name="twitter:image" content={"https://www.completecompendium.com" + '/images/grf/' +  pageContext.category + '.gif'}/>
      </>
      }
      <meta property="og:image:width" content="300"/>
      <meta property="og:image:height" content="360"/>
      
            
      {/* <meta name="description" content={ getMonsterDescription(pageContext.monster_key ,pageContext.monster_data.fullBody) } /> */}
      {/* Image: "/images/monsters/img/" + monster_page_data.monster_key + ".gif" */}
      <meta name="twitter:card" content="summary_large_image"/>
      <meta name="twitter:url" content={"https://www.completecompendium.com/catalog/" + pageContext.category} />
      <meta name="twitter:title" content="Advanced Dungeons & Dragons 2nd Edition Complete Compendium" />
      <meta name="twitter:description" content={ "Catalog page, for the " + AcronymToSetting[pageContext.category] + "campaign settings" } />
          
    </>
  )
  

export default SettingTemplate;


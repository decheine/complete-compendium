

import React from "react";

import Layout from "@components/Layout";
// import * as settingStyles from "@styles/modules/settings.module.css"

import { BookList } from "@components/BookList";
import { Link } from "gatsby";

import * as bookStyles from '@styles/modules/book.module.css'


// import './SettingPage.css'
const ACRONYMS = require('@data/CatAcronyms.json')
const AcronymToSetting = require('@data/AcronymsSetting.json')
const KeyToTitles = require('@data/AA_KEYS_TITLES.json')
const settings = require("../../data/settings.json")
const Catalog = require('@data/Full_Catalog.json')

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

interface BookMonstersProps {
    setting_key: string
}

type setting_type = {
    setting_key: string,
    setting_name: string,
    source_books: Array<string>
}

type catalog_entry = {
    author: string,
    monster_keys: string[],
    publish_id: string,
    setting: string,
    title: string,
    year: string
}


// List of monster
function BookMonstersList(props: BookMonstersProps) {
    console.log(props)
    let setting_books: string[] = []
    settings.forEach((target_setting: setting_type) => {
        if (target_setting.setting_key == props.setting_key) {
            setting_books = target_setting.source_books
        }
    })
    console.log(setting_books)
    let setting_monsters: string[] = []
    let setting_book_monsters = {}
    let monster_links: JSX.Element[] = []

    


    Catalog.forEach((book: catalog_entry) => {
        if (setting_books.includes(book.publish_id)){
            // append this books mosnters to setting_monsters
            setting_book_monsters[book.publish_id] = book.monster_keys
        }
    })
    console.log("Setting book monsters")
    
    console.log(setting_book_monsters)

    setting_books.forEach((publish_id: string) => {
        console.log(publish_id)
        console.log(setting_book_monsters[publish_id])
        setting_book_monsters[publish_id].forEach((monster_key: string) => {
            monster_links = monster_links.concat(
                <>
                <Link to={'/catalog/' + props.setting_key + "/" + publish_id + "/" + monster_key} className={bookStyles.listLink} key={monster_key}>
                          <div className={bookStyles.listEntry} >
                              {KeyToTitles[monster_key]}
                          </div>
                          </Link>
                </>
            )
        });
    })


    return monster_links

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
                    List of all monsters across these books.
                    <BookMonstersList setting_key={pageContext.category}/>

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


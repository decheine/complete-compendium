

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
                <Layout>

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

export default SettingTemplate;
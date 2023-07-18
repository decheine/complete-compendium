import React, { useEffect, useState } from "react";

// REFACTOR THIS To instead call API to get the data it needs
// and then build the result.

import './CategoriesList.css'
// import CatAcronyms from '../../../data/CatAcronyms.json'
const ACRONYMS = require('../data/CatAcronyms.json')
const WORLDS = require('../data/CatWorlds.json')
// import { Router, Switch, Route } from 'react-router';

// import { SettingPage } from "./SettingPage";

import data_settings from '../data/settings.json'

type SettingType = {
    setting_key: string,
    setting_name: string,
    source_books: Array<string>,
    createdAt: string,
    updatedAt: string
  }

export function CategoriesList(){
    const [settings, setSettings] = useState(new Array<SettingType>())
    const [settingNames, setNames] = useState(new Array<string>())
    
    // create a map from setting to book list from the global.settings

    useEffect(() => {
        const fetchData = async () => {
            // get the data from the api
            const dataSettings = data_settings
        
            var tmpNames = new Array<string>()
            for(let i = 0; i < dataSettings.length; i++){
                tmpNames.push(dataSettings[i].setting_name);
            }

            // set state with the result
            setSettings(dataSettings)
            setNames(tmpNames)
        }
        
        // call the function
        fetchData()
        
        
    }, [])

    
    // console.log("settings: ", settings, settingNames)

    return (
        <>
        
        
        <div className="CategoryList">
            {settingNames.map(( category: string)=>{
                return (
                    <div className={"setting-frame"} title={category} key={category}>
                        <a href={`/catalog/${ACRONYMS[category]}`} className="category">
                            <div className="setting-button">
                                <img className="catImg" src={'/images/grf/' +  ACRONYMS[category] + '.gif'} alt={category + 'image'}></img>
                                
                                <div className="setting-subtitle">
                                    <div className="setting-title">{category}</div>
                                    <div className="setting-world">{WORLDS[category]}</div>
                                </div>
                            </div>
                        </a>
                    </div>
                );
            })}
        </div>
        
        </>
    )
    
}
import React, { useEffect, useState } from "react";

// REFACTOR THIS To instead call API to get the data it needs
// and then build the result.

import './CategoriesList.css'
import { Link } from "gatsby";
// import CatAcronyms from '../../../data/CatAcronyms.json'
const ACRONYMS = require('../data/CatAcronyms.json')
const WORLDS = require('../data/CatWorlds.json')
// import { Router, Switch, Route } from 'react-router';

// import { SettingPage } from "./SettingPage";

const data_settings = require('../data/settings.json')
const settings_list = require('@data/AcronymsSetting.json')

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

    let buffer: React.JSX.Element[] = []

    Object.entries(settings_list).forEach(([key, value], index) => {
        
        // name Bobby Hadz 0
        // country Chile 1
        // console.log(key, value, index);
        // console.log(`${key}: ${value}`);
        if(typeof value !== 'string'){

        } else {
            buffer.push(
                <div className={"setting-frame"} title={key} key={key}>
                    <Link to={`/catalog/${key}`} className="category">
                        <div className="setting-button">
                            <img className="catImg" src={'/images/grf/' +  key + '.gif'} alt={value + 'image'}></img>
                            
                            <div className="setting-subtitle">
                                <div className="setting-title">{value}</div>
                                <div className="setting-world">{WORLDS[settings_list[key]]}</div>
                            </div>
                        </div>
                    </Link>
                </div>
            )
        }
      });

    
    // console.log("settings: ", settings, settingNames)

    return (
        <>
        
        
        <div className="CategoryList">
            {buffer}
        </div>
        
        </>
    )
    
}
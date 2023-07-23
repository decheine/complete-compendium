import React from 'react'
import { useEffect, useState } from "react";

import MonsterLink from '../components/MonsterLink';
import Layout from '../components/Layout';
import styled from 'styled-components';

const keys_titles_json: Map<string,string> = require('../data/AA_KEYS_TITLES.json')

type MonsterLinksProps = {
    monster_keys: Map<string, string>,
}

const MonsterLinksWrapper = styled.div`
    align-items: center;
    display: flex;
    flex-direction: row;
    flex-wrap: wrap;
    justify-content: space-between;
    margin-top: 1rem;
`

//for each monster_key in the KEYS_TITLES, display a link to the monster page
const MonsterLinks = (props: MonsterLinksProps) => {

    // let arr = Array.from(props.monster_keys.keys())
    // console.log(arr)
    // console.log("monster keys:", props.monster_keys)
    const monster_map = props.monster_keys
    const monster_keys = Array.from(Object.keys(props.monster_keys)).sort((a, b) => a.localeCompare(b))
    
    const monster_links = monster_keys.map(monster_key => {
        // console.log()
        return (
            <MonsterLink key={monster_key} monster_key={monster_key} monster_title={monster_map[monster_key] ? props.monster_keys[monster_key]! : ""} />
        )
    }
    )
    return (
        <>
        <MonsterLinksWrapper>
            {monster_links}
        </MonsterLinksWrapper>
        </>
    )
}

const flip = (data: { [s: string]: unknown; } | ArrayLike<unknown>) => Object.fromEntries(
    Object
      .entries(data)
      .map(([key, value]) => [value, key])
    );

export function appendix() {
    // Set up the page variables
    // const itemCount = KEYS_TITLES.length;
    // if(typeof document !== 'undefined'){
    //     document.title = "Appendix - Complete Compendium"
    // }
    const [titles, setTitles] = useState(new Map<string, string>())
    

    // const flipped_titles: Map<string, string> = flip(keys_titles_json)
    // console.log(flipped_titles)
    

    return (
        // upper page with category links
        <>
        <Layout url='/appendix'>
            
        <div className='background-appendix'>

        {/* <CategoriesList/> */}
        <div className="AppendixDescription">Browse monster source books by setting or browse all at once.</div>

        {
            // keys_titles_json
            <MonsterLinks monster_keys={keys_titles_json}/>
            // : 
            // <div key='loading'>
            // Loading...
            // </div>
        }
        


        </div>
        </Layout>
        </>

        // lower page with all book list
    );
}
export default appendix;
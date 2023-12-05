import React from 'react'

import MonsterLink from '../components/MonsterLink';
import Layout from '../components/Layout';
import styled from 'styled-components';
import { HeadProps } from 'gatsby';
import CSS from 'csstype';

const keys_titles_json: Map<string, string> = require('../data/AA_KEYS_TITLES.json')

const titles_keys_json: Map<string, string> = require('../../data/Titles_Keys.json')

type MonsterLinksProps = {
    monster_keys: Map<string, string>,
}

type AllMonsterLinksProps = {
    titles_keys: Map<string, string>,
}

const MonsterLinksWrapper = styled.div`
    align-items: center;
    display: flex;
    flex-direction: row;
    flex-wrap: wrap;
    justify-content: space-between;
    margin-top: 1rem;
`

const MonsterLinksWrapperStyle: CSS.Properties = {
    alignItems: "center",
    display: "flex",
    flexDirection: "row",
    flexWrap: "wrap",
    justifyContent: "space-between",
    marginTop: "1rem",
}

type DataProps = {
    site: {
        siteMetadata: {
            title: string
        }
    }
}

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
            <MonsterLink key={monster_key} monster_key={monster_key} monster_title={monster_map[monster_key as keyof typeof monster_map] ? props.monster_keys[monster_key as keyof typeof monster_map] as string : ""} />
        )
    }
    )
    return (
            // <div style={MonsterLinksWrapperStyle}>
            <div className='MonsterLinksWrapper'>
                {monster_links}
            </div>
    )
}

const AllMonsterLinks = (props: AllMonsterLinksProps) => {

    // let arr = Array.from(props.monster_keys.keys())
    // console.log(arr)
    // console.log("monster keys:", props.monster_keys)
    const titles_keys: Map<string, string> = props.titles_keys
    // const monster_titles = Array.from(Object.keys(props.titles_keys)).sort((a, b) => a.localeCompare(b))
    let monster_links: JSX.Element[] = []

    // const monster_links = titles_keys.map(([monster_title, monster_key]) => {
    //     // console.log()
    //     return (
    //         <MonsterLink key={monster_title} monster_key={monster_key} monster_title={monster_title} />
    //     )
    // }
    
    Object.keys(titles_keys).forEach((monster_title: string)=>{
        // const key: (keyof typeof titles_keys) = monster_title;
        // log out each entry
        monster_links.push(
            <MonsterLink key={monster_title} monster_key={titles_keys[monster_title as keyof typeof titles_keys] as string} monster_title={monster_title} />
        )
      })
    
    return (
            // <div style={MonsterLinksWrapperStyle}>
            <div className='MonsterLinksWrapper'>
                {monster_links}
            </div>
    )
}

const flip = (data: { [s: string]: unknown; } | ArrayLike<unknown>) => Object.fromEntries(
    Object
        .entries(data)
        .map(([key, value]) => [value, key])
);

export function appendix() {
    return (
        <>
            <Layout url='/appendix'>
                <div className='background-appendix'>
                    <div className="AppendixDescription">Browse monster source books by setting or browse all at once.</div>
                    <AllMonsterLinks titles_keys={titles_keys_json} />
                </div>
            </Layout>
        </>
    );
}
export default appendix;

export function Head(props: HeadProps<DataProps>) {
    return (
        <>
            <title>Appendix - AD&D 2e Complete Compendium</title>
        </>
    )
}
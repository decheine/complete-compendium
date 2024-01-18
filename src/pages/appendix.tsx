import React, { useState } from 'react'

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
    titles: string[],
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

const AlphSectionWrapperStyle: CSS.Properties = {
    alignItems: "flex-start",
    display: "flex",
    flexDirection: "column",
    flexWrap: "wrap",
    marginTop: "1rem",
}

const AlphHeaderStyle: CSS.Properties = {
    fontFamily: "frizquadrata_ltbold",
    paddingLeft: "0.5em",
    fontSize: "x-large",
    marginBlockStart: "0em",
    marginBlockEnd: "0em",
    marginInlineStart: "0px",
    marginInlineEnd: "0px",
}

const alphHrStyle: CSS.Properties = {
    width: "100%",
    backgroundColor: "#1250A2",
    height: "2px"
}

type DataProps = {
    site: {
        siteMetadata: {
            title: string
        }
    }
}
// Split into groups based on first character, sorted alphabetically
const groupIt = (array: Array<string>) => {
    let resultObj: Map<string, Array<string>> = new Map<string, Array<string>>();
    
    for (let i =0; i < array.length; i++) {
        let currentWord: string = array[i];
        let firstChar: string = currentWord[0].toLowerCase();
        let innerArr: Array<string> = [];
        if (resultObj[firstChar] === undefined) {
            innerArr.push(currentWord);
        resultObj[firstChar] = innerArr
        }else {
        resultObj[firstChar].push(currentWord)
        }
    }
    return resultObj
}

//for each monster_key in the KEYS_TITLES, display a link to the monster page
const MonsterLinks = (props: MonsterLinksProps) => {
    const monster_map = props.monster_keys
    const monster_keys = Array.from(Object.keys(props.monster_keys)).sort((a, b) => a.localeCompare(b))

    const monster_links = monster_keys.map(monster_key => {
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
    const titles_keys: Map<string, string> = props.titles_keys
    // const monster_titles = Array.from(Object.keys(props.titles_keys)).sort((a, b) => a.localeCompare(b))
    let monster_links: JSX.Element[] = []
    Object.keys(titles_keys).forEach((monster_title: string)=>{
        // const key: (keyof typeof titles_keys) = monster_title;
        // log out each entry
        monster_links.push(
            <MonsterLink key={monster_title} monster_key={titles_keys[monster_title as keyof typeof titles_keys] as string} monster_title={monster_title} />
        )
      })
    
    return (
            <div className='MonsterLinksWrapper'>
                {monster_links}
            </div>
    )
}

const AlphMonsterLinks = (props: MonsterLinksProps) => {
    let alphabet_groups: JSX.Element[] = []

    const monster_map = props.monster_keys
    const monster_titles: Array<string> = Object.values(props.monster_keys).sort((a, b) => a.localeCompare(b))

    // Reverse it
    const monster_title_keys = new Map(Array.from(monster_map, entry => [entry[1], entry[0]]));
    // const monster_titles: Array<string> = Array.from(Object.keys(monster_title_keys))

    const grouped_alph_monsterkeys: Map<string, Array<string>> = groupIt(monster_titles)
    
    Object.keys(grouped_alph_monsterkeys).forEach((letter: string, index: number, monster_titles: string[]) => {
        const alph_monster_links = grouped_alph_monsterkeys[letter].map(monster_title => {
            return (
                // <div key={monster_title}>
                <MonsterLink key={monster_title} monster_key={monster_title_keys[monster_title]} monster_title={monster_title} />
                // </div>
            )
        })
        alphabet_groups.push(
            // Letter as a header
            <div key={letter} style={AlphSectionWrapperStyle}>
                <h2 style={AlphHeaderStyle}>{letter.toLocaleUpperCase()}</h2>
                <hr style={alphHrStyle}/>
                <div key={letter} className="MonsterLinksWrapper">
                    {alph_monster_links}
                </div>
            </div>
        )
    });

    return (
        <div>
            {alphabet_groups}
        </div>
    )
}

const AlphAllMonsterLinks = (props: AllMonsterLinksProps) => {
    let alphabet_groups: JSX.Element[] = []

    const monster_map = props.titles_keys
    const monster_titles: Array<string> = Object.keys(props.titles_keys).sort((a, b) => a.localeCompare(b))

    // Reverse it
    const monster_title_keys = new Map(Array.from(monster_map, entry => [entry[1], entry[0]]));
    // const monster_titles: Array<string> = Array.from(Object.keys(monster_title_keys))

    const grouped_alph_monsterkeys: Map<string, Array<string>> = groupIt(monster_titles)
    console.log(grouped_alph_monsterkeys)
    
    Object.keys(grouped_alph_monsterkeys).forEach((letter: string, index: number, monster_titles: string[]) => {
        const alph_monster_links = grouped_alph_monsterkeys[letter].map(monster_title => {
            return (
                // <div key={monster_title}>
                <MonsterLink key={monster_title} monster_key={monster_map[monster_title]} monster_title={monster_title} />
                // </div>
            )
        })
        alphabet_groups.push(
            // Letter as a header
            <div key={letter} style={AlphSectionWrapperStyle}>
                <h2 style={AlphHeaderStyle}>{letter.toLocaleUpperCase()}</h2>
                <hr style={alphHrStyle}/>
                <div key={letter} className="MonsterLinksWrapper">
                    {alph_monster_links}
                </div>
            </div>
        )
    });

    return (
        <div>
            {alphabet_groups}
        </div>
    )
}

const FilterableMonsterLinks = (props: AllMonsterLinksProps) => {
    let alphabet_groups: JSX.Element[] = []

    const monster_map = props.titles_keys
    // const monster_titles: Array<string> = Object.keys(props.titles_keys).sort((a, b) => a.localeCompare(b))
    const monster_titles: string[] = props.titles

    // Reverse it
    const monster_title_keys = new Map(Array.from(monster_map, entry => [entry[1], entry[0]]));
    // const monster_titles: Array<string> = Array.from(Object.keys(monster_title_keys))

    const grouped_alph_monsterkeys: Map<string, Array<string>> = groupIt(monster_titles)
    // console.log(grouped_alph_monsterkeys)
    
    Object.keys(grouped_alph_monsterkeys).forEach((letter: string, index: number, monster_titles: string[]) => {
        const alph_monster_links = grouped_alph_monsterkeys[letter].map(monster_title => {
            return (
                // <div key={monster_title}>
                <MonsterLink key={monster_title} monster_key={monster_map[monster_title]} monster_title={monster_title} />
                // </div>
            )
        })
        alphabet_groups.push(
            // Letter as a header
            <div key={letter} style={AlphSectionWrapperStyle}>
                <h2 style={AlphHeaderStyle}>{letter.toLocaleUpperCase()}</h2>
                <hr style={alphHrStyle}/>
                <div key={letter} className="MonsterLinksWrapper">
                    {alph_monster_links}
                </div>
            </div>
        )
    });

    return (
        <div>
            {alphabet_groups}
        </div>
    )
}


const flip = (data: { [s: string]: unknown; } | ArrayLike<unknown>) => Object.fromEntries(
    Object
        .entries(data)
        .map(([key, value]) => [value, key])
);


function FilterMonsters() {
    const [filter, setFilter] = useState('');
    const filtered_titles = Object.keys(titles_keys_json).filter(f => f.toLowerCase().includes(filter.toLocaleLowerCase()) || filter === '')
    
    return (
      <div className="App">
        <p>
          <input id="filter"
            name="filter"
            type="text"
            value={filter}
            onChange={event => setFilter(event.target.value)}
          />
        </p>
        <FilterableMonsterLinks titles={filtered_titles} titles_keys={titles_keys_json} />
      </div>
    );
  }


export function appendix() {
    return (
        <>
            <Layout url='/appendix'>
                <div className='background-appendix'>
                    <div className="AppendixDescription">
                        All monsters, alphabetically grouped by their monster titles. This list is exhaustive and redundant, for good purpose. Monsters go by many names, and exploring the monsters is much better with many different names for the same monster. Type in the field below to filter this list.</div>
                    {/* <AllMonsterLinks titles_keys={titles_keys_json} /> */}
                    {/* <AlphAllMonsterLinks titles={Object.keys(titles_keys_json)} titles_keys={titles_keys_json} /> */}
                    {/* <FilterableMonsterLinks titles={Object.keys(titles_keys_json)} titles_keys={titles_keys_json} /> */}
                    <FilterMonsters/>
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
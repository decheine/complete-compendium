// Random monster button.
import React from "react"
import { useState, useEffect } from 'react';
import CSS from 'csstype';
import { Link } from "gatsby";

import AA_KEYS_TITLES from '../data/AA_KEYS_TITLES.json'

function getRandomInt(max: number) {
    return Math.floor(Math.random() * max);
}

const randomButtonStyleHome: CSS.Properties = {
    marginBlockStart: "unset",
    marginBlockEnd: "unset",
    marginInlineStart: "unset",
    marginInlineEnd: "unset",
    position: "relative",
    fontFamily: "Leksa Sans DemiBold",
    fontStyle: "normal",
    fontWeight: 600,
    fontSize: "24px",
    display: "flex",
    alignItems: "center",
    textAlign: "center",
    textDecoration: "none",
    textTransform: "capitalize",
    color: "white",
    paddingTop: "1rem",
    paddingBottom: "1rem",
    paddingLeft: "2rem",
    paddingRight: "2rem",
    zIndex: 1,
}

const randomButtonStylePage: CSS.Properties = {
    marginBlockStart: "unset",
    marginBlockEnd: "unset",
    marginInlineStart: "unset",
    marginInlineEnd: "unset",
    position: "relative",
    fontFamily: "Leksa Sans DemiBold",
    fontStyle: "normal",
    fontWeight: 600,
    fontSize: "18px",
    display: "flex",
    alignItems: "center",
    textAlign: "center",
    textDecoration: "none",
    textTransform: "capitalize",
    color: "white",
    zIndex: 1,
}

const randomButtonStyleInner: CSS.Properties = {
    position: "relative",
    fontFamily: "Leksa Sans DemiBold",
    fontStyle: "normal",
    fontWeight: 400,
    display: "flex",
    alignItems: "center",
    textAlign: "center",
    textDecoration: "none",
    textTransform: "capitalize",
    color: "white",
    paddingTop: "2mm",
    paddingBottom: "2mm",
    paddingLeft: "1.5rem",
    paddingRight: "1.5rem",
    zIndex: 1,
}


const RandomMonsterButton = (props: { home: Boolean }) => {
    const [monster_key, setMonsterKey] = useState('');
    // const [monster_title, setMonsterTitle] = useState('');

    const getRandomMonster = () => {
        // if DataService.monsterTitles is undefined
        const monsterKeys = Object.keys(AA_KEYS_TITLES);
        //console.log("Random. localmonsterkeys",monsterKeys  )
        if (monsterKeys !== undefined) {

            const random_key = monsterKeys[getRandomInt(monsterKeys.length)];
            setMonsterKey(random_key);
        }
    }

    useEffect(() => {
        getRandomMonster();
    }, []);
    let randomButtonStyle: CSS.Properties
    if (props.home) {
        randomButtonStyle = randomButtonStyleHome
    } else {
        randomButtonStyle = randomButtonStylePage
    }

    return (
        <div style={randomButtonStyle}>
            <Link to={"/appendix/" + monster_key} style={{ textDecoration: "none" }}>
                <div style={randomButtonStyleInner} onClick={getRandomMonster}>Random Monster</div>
                {/* <div className="random-button" onClick={getRandomMonster}>Random Monster</div> */}
            </Link>
        </div>
    );
}

export default RandomMonsterButton;
// Random monster button.
import React from "react"

import { useState, useEffect } from 'react';
// import { Link } from 'react-router-dom';

import './RandomMonsterButton.css';

import AA_KEYS_TITLES from '../data/AA_KEYS_TITLES.json'
import { Link } from "gatsby";

function getRandomInt(max: number) {
    return Math.floor(Math.random() * max);
  }

const RandomMonsterButton = () => {
    const [monster_key, setMonsterKey] = useState('');
    // const [monster_title, setMonsterTitle] = useState('');

    const getRandomMonster = () => {
        // if DataService.monsterTitles is undefined
        const monsterKeys = Object.keys(AA_KEYS_TITLES);
        //console.log("Random. localmonsterkeys",monsterKeys  )
        if(monsterKeys !== undefined){

            const random_key = monsterKeys[getRandomInt(monsterKeys.length)];
            setMonsterKey(random_key);
        }
    }

    useEffect(() => {
        getRandomMonster();
    }, []);

    return (
        <div className="RandomMonsterButton">
            <Link to={"/appendix/" + monster_key}>
                <div className="random-button" onClick={getRandomMonster}>Random Monster</div>
            </Link>
        </div>
    );
}

export default RandomMonsterButton;
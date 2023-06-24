// Random monster button.

import React, { useState, useEffect } from 'react';
import { Link, useParams } from 'react-router-dom';
// import { DataService } from '../../services/DataService';
import { GLOBALS } from '../../../data/GLOBALS';

import './RandomMonsterButton.css';

function getRandomInt(max: number) {
    return Math.floor(Math.random() * max);
  }

const RandomBookButton = () => {
    const [monster_key, setMonsterKey] = useState('');
    const [monster_title, setMonsterTitle] = useState('');

    const getRandomMonster = () => {
        // if DataService.monsterTitles is undefined
        if(global.monster_keys !== undefined){

            const random_key = global.monster_keys[getRandomInt(monster_keys.length)];
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

export default RandomBookButton;
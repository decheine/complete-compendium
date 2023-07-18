import axios from 'axios';
import React from 'react';

import { Link } from "gatsby";
import { GLOBALS } from '../data/GLOBALS';

const KeyToTitles = require('@data/AA_KEYS_TITLES.json')


type MonsterListProps = {
    monster_keys: string[];
    url_suffix: string;
}

const monsterListStyles = {
    
}

function MonsterList(props: MonsterListProps) {
    
  return (
    <div className="list-container">
        <div className="list-flexbox">
            <>
                {props.monster_keys.sort().map((monster_key: string) => {
                    // console.log("monster_key: ", monster_key)
                    return (
                            <Link to={props.url_suffix + monster_key} className="list-link" key={monster_key}>
                            <div className="list-entry" >
                                {KeyToTitles[monster_key]}
                            </div>
                            </Link>
                    )
                }
                )
                }
            </>
        </div>
    </div>
);
}

export default MonsterList;
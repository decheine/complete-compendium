import "./MonsterLink.css"

import React from "react";

import { Link, type HeadFC, type PageProps } from "gatsby"
import styled from "styled-components"


// import { Link } from "react-router-dom";

// define type for MonsterLink props
interface MonsterLinkProps {
    monster_key: string;
    monster_title: string;
}


const monsterLinkStyle = {
    // color: "#8A6534",
    // padding: 4,
    // backgroundColor: "#FFF4DB",
    fontSize: "1rem",
    flex: "1 1 160px",
    flexBasis: "30%",
  }

const MonsterLink = ( {monster_key, monster_title }: MonsterLinkProps) => {
    return (
        // <div style={monsterLinkStyle}>
        <div className="MonsterLinkWrapper">
            <Link to={`/appendix/${monster_key}`} className="monster-link" >{monster_title}</Link>
        </div>
    )
}

export default MonsterLink;
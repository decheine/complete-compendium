// import MonsterLink.css

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
    color: "#8A6534",
    padding: 4,
    backgroundColor: "#FFF4DB",
    fontSize: "1.25rem",
  }
const MonsterLinkWrapper = styled.div`
  flex: 1 1 160px;
  flex-basis: 30%;
`

const MonsterLink = ( {monster_key, monster_title }: MonsterLinkProps) => {
    return (
        <MonsterLinkWrapper>
            <Link to={`/appendix/${monster_key}`} className="monster-link" >{monster_title}</Link>
        </MonsterLinkWrapper>
    )
}

export default MonsterLink;
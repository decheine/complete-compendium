import React from "react"
import Layout from '../components/Layout';
import {  PageProps, Link, HeadFC, graphql  } from "gatsby";

// import MonsterList from '@components/MonsterList.tsx'

import { CreatePagesArgs } from 'gatsby';

import * as bookStyles from '@styles/modules/book.module.css'

const KeyToTitles = require('@data/AA_KEYS_TITLES.json')
const CatAcronyms = require('@data/CatAcronyms.json')
const publish_id_to_acronym = require('@data/publishId_to_acronym.json')


/* Example
{
    "author" : "Richard W and Anne Brown",
    "monster_keys" : [ "straweed", "weisshun", "yphoz" ],
    "publish_id" : "9289",
    "setting" : "Greyhawk",
    "title" : "WGA2 Falconmaster",
    "year" : "1990"
},
*/

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
              {props.monster_keys?.sort().map((monster_key: string) => {
                  // console.log("monster_key: ", monster_key)
                  return (
                          <Link to={props.url_suffix + monster_key} className={bookStyles.listLink} key={monster_key}>
                          <div className={bookStyles.listEntry} >
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


type BookPageContext = {
    author?: string
    monster_keys: string[]
    publish_id: string
    setting: string
    title: string
    year: string
}

type BookDataWrapper = {
  pageContext: BookPageContext
}

interface Props {
  pageContext: BookDataWrapper
  }

const BookTemplate: React.FC<Props> = ({ pageContext }) => {
  
//   console.log("book", pageContext)  
//   console.log("book sub", pageContext.pageContext)  
  const book_data = pageContext.pageContext
  const book_title = book_data.title
  const author = book_data.author
  const setting = book_data.setting
  const publish_id = book_data.publish_id
  const year = book_data.year
  const monster_keys = book_data.monster_keys
//   console.log("book template")
//   console.log("Title", book_title)
//   console.log("Author", author)

  let image_placeholder = "https://upload.wikimedia.org/wikipedia/commons/6/65/No-Image-Placeholder.svg"

  // const { book_data } = data
  return (
    <Layout url={`/catalog/${CatAcronyms[setting]}/${publish_id}`}>
      <div className="frame">
                <div className={bookStyles.card1}>
                    <div className={bookStyles.col1}>
                        <img src={'/images/Books/Hi Resolution/' +  publish_id + '.jpg'} className={bookStyles.cardImg}
                        alt="Book Cover (alt text coming soon)"
                        onError={({currentTarget}) => {
                            currentTarget.onerror = null;
                            currentTarget.alt = "This monster is missing it's image. It will be found eventually.";
                            currentTarget.src = image_placeholder;
                            currentTarget.title = "Missing book cover image of " + book_title;
                        }}/>
                    </div>
                    <div className={bookStyles.col2}>
                        <h5 className={bookStyles.cardTitle}>{book_title}</h5>
                        <div className={bookStyles.cardBody}>
                            <div className={bookStyles.cardText}>
                                <ul>
                                    <li>
                                        <strong>Author:</strong>  {author}
                                    </li>
                                    <li>
                                        <strong>Year:</strong> {year}
                                    </li>
                                    <li>
                                        <strong>Monster Count:</strong> {monster_keys?.length}
                                    </li>
                                </ul>
                            </div>
                        </div>
                    </div>
                </div>
            </div>

            {/* Monster List */}
            <h3>Monsters</h3>
            <MonsterList monster_keys={monster_keys} url_suffix={'/catalog/' + CatAcronyms[setting] + "/" + publish_id + "/"}/>
        
    </Layout>
  )
}

/*
type BookPageContext = {
    author?: string
    monster_keys: string[]
    publish_id: string
    setting: string
    title: string
    year: string
}
*/

export const Head: React.FC<Props> = ({ pageContext }) => (
    <>
      <title>{pageContext.pageContext.title} - AD&D Complete Compendium</title>
      <meta property="og:site_name" content="AD&D 2nd Edition Complete Monstrous Compendium"/>
      <meta property="og:title" content={pageContext.pageContext.title  + " | AD&D Complete Compendium"}/>
      <meta property="og:description" content={ "Catalog page, for the " + pageContext.pageContext.title + "book." }/>
      <meta property="og:url" content={"https://www.completecompendium.com" + '/catalog/' + publish_id_to_acronym[pageContext.pageContext.publish_id] + '/' + pageContext.pageContext.publish_id}/>
      <meta property="og:type" content="website"/>
      {
        <>
        <meta property="og:image" content={"https://www.completecompendium.com" + '/images/Books/Hi Resolution/' +  pageContext.pageContext.publish_id + '.jpg'}/>
        <meta name="twitter:image" content={"https://www.completecompendium.com" + '/images/Books/Hi Resolution/' +  pageContext.pageContext.publish_id + '.jpg'}/>
      </>
      }
      <meta property="og:image:width" content="300"/>
      <meta property="og:image:height" content="360"/>
      
            
      {/* <meta name="description" content={ getMonsterDescription(pageContext.monster_key ,pageContext.monster_data.fullBody) } /> */}
      {/* Image: "/images/monsters/img/" + monster_page_data.monster_key + ".gif" */}
      <meta name="twitter:card" content="summary_large_image"/>
      <meta name="twitter:url" content={"https://www.completecompendium.com/catalog/" + pageContext.pageContext.publish_id} />
      <meta name="twitter:title" content="Advanced Dungeons & Dragons 2nd Edition Complete Compendium" />
      <meta name="twitter:description" content={ "Catalog page, for the book" + pageContext.pageContext.title + "campaign settings" } />
          
    </>
  )

export default BookTemplate

export const query = graphql`
  {
    sitePage {
      pageContext
    }
  }
`
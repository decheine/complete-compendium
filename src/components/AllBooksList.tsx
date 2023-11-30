import React from 'react'
import BookCard from './BookCard'
import CSS from 'csstype';

// import './BookList.css'
const BOOKS = require('../data/sortedtsr.json')
const Categories = require('../data/Categories.json')
const CatAcronyms = require('../data/CatAcronyms.json')

const bookListStyle: CSS.Properties = {
    display: "flex",
    flexWrap: "wrap",
    justifyContent: "space-evenly"
}

export function AllBooksList() {

    const items = []
    // console.log(BOOKS)
    // Iterate through all BOOKS and push a BookCard for each one
    var books_setting: any = {}
    for (const [index, value] of Object.entries(Categories)){
        for(const val of value as string[]){
            books_setting[val] = CatAcronyms[index]     
        }
        // books_setting[value as string] = CatAcronyms[index]
    }

    for (const [index] of Object.entries(BOOKS)){
        // console.log(index, value)
        items.push(<BookCard key={index} id={index} category={books_setting[index]} title={BOOKS[index as string]}/> )
    }
    
    return (
        <div style={bookListStyle}>
        {items}
        </div>
    )
}
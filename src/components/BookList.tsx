import React from 'react'
import BookCard from '../../BookCard/BookCard'

import './BookList.css'
const Categories = require('../../../data/Categories.json')
const Acronyms = require('../../../data/AcronymsSetting.json')
const BOOKS = require('../../../data/sortedtsr.json')



// REFACTOR TO FETCH BOOKS FROM API


export function BookList(props: any) {
    console.log("Booklist: ", props.category)
    const books = Categories[Acronyms[props.category]]
    console.log(books)
    const items = []
    books.sort()
    for (const [index, value] of books.entries()){
        console.log(index)
        items.push(<BookCard key={value} id={value} category={props.category} title={BOOKS[value]}/> )
    }
    
    return (
        <div className="BookList">
        {items}
        </div>
    )
}
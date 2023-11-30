import React from 'react'
import BookCard from './BookCard'
import BookListView from './BookListView'
import CSS from 'csstype';

// import './BookList.css'
const Categories = require('@data/Categories.json')
const Acronyms = require('@data/AcronymsSetting.json')
const BOOKS = require('@data/sortedtsr.json')

const catalog_data = require('@data/Full_Catalog.json')


// List View Buttons




export function BookList(props: any) {
    const cardViewStyle: CSS.Properties = {
        display: "flex",
        // flexWrap: "wrap",
        justifyContent: "space-evenly",
    }
    
    const listViewStyle: CSS.Properties = {
        display: "flex",
        flexWrap: "wrap",
        justifyContent: "space-evenly",
        flexDirection: "column"
    }
    
    // console.log("Booklist: ", props.category)
    const books = Categories[Acronyms[props.category]]
    // console.log(books)
    const card_items = []
    const list_items = []
    books.sort()
    for (const [index, value] of books.entries()){
        // console.log(index)
        card_items.push(<BookCard key={value} id={value} category={props.category} title={BOOKS[value]}/> )
    }

    for (const [index, publish_id] of books.entries()){

        var book_object = catalog_data.find((obj: { publish_id: number }) => {
            return obj.publish_id === publish_id
          })
        // console.log(index)
        list_items.push(<BookListView key={publish_id} id={publish_id} category={props.category} title={BOOKS[publish_id]} author={book_object.author} book_object={book_object}/> )
    }

    
    
    return (
        <div style={listViewStyle}>
        {list_items}
        </div>
    )
}
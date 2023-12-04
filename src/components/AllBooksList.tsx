import React from 'react'
import BookCard from './BookCard'
import { BookList } from '~/src/components/BookList';
import CSS from 'csstype';
import BookListView from '../components/BookListView';



// const BOOKS = require('@data/sortedtsr.json')
const BOOKS = require('../../data/all_tsr.json')
const Categories = require('@data/Categories.json')
const CatAcronyms = require('@data/CatAcronyms.json')
const Full_Catalog = require('@data/Full_Catalog.json')
const SettingTitleToAcryonym =require('@data/SettingTitleToAcronym.json')

const bookListStyle: CSS.Properties = {
    display: "flex",
    flexWrap: "wrap",
    justifyContent: "space-evenly"
}

type Entries<T> = {
    [K in keyof T]: [K, T[K]];
}[keyof T][];

const getEntries = <T extends object>(obj: T) => Object.entries(obj) as Entries<T>;

type BookObjectType = {
    author : string,
    monster_keys : Array<string>,
    publish_id : string,
    setting : string,
    title : string,
    year : string
 }

 type BookListProps = {
    id: string,
    category: string,
    title: string,
    author: string,
    book_object: BookObjectType
}

export function AllBooksList() {

    const items = []
    // console.log(BOOKS)
    // Iterate through all BOOKS and push a BookCard for each one
    var books_setting: any = {}
    for (const [index, value] of Object.entries(Categories)) {
        for (const val of value as string[]) {
            books_setting[val] = CatAcronyms[index]
        }
        // books_setting[value as string] = CatAcronyms[index]
    }

    for (const [index] of Object.entries(BOOKS)) {
        // console.log(index, value)
        items.push(<BookCard key={index} id={index} category={books_setting[index]} title={BOOKS[index as string].title} />)
    }

    const list_items = []

    Full_Catalog.sort((a: BookObjectType, b: BookObjectType) => (a.publish_id < b.publish_id ? -1 : 1));
    for (const [index, book_object] of Object.entries(Full_Catalog) as Entries<typeof Full_Catalog>) {

        // var book_object = catalog_data.find((obj: { publish_id: number }) => {
        //     return obj.publish_id === publish_id
        // })
        // console.log(index)
        list_items.push(<BookListView key={book_object.publish_id} id={book_object.publish_id} category={SettingTitleToAcryonym[book_object.setting]} title={book_object.title} author={book_object?.author} book_object={book_object} />)
    }
    

    return (
        <div style={bookListStyle}>
            {list_items}
        </div>
    )
}
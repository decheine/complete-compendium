import React from 'react';

/**
 * 
 * @param {*} props 
 * img = path to image file
 * description = description card text
 * header = header text
 * @returns 
 */


// import "./BookCard.css"

import * as bookListStyle from "@styles/modules/booklist.module.css"
import { Link } from 'gatsby';

type BookObjectType = {
    author : string,
    monster_keys : Array<string>,
    publish_id : string,
    setting : string,
    title : string,
    year : string
 }
// BookCard props type
type BookListProps = {
    id: string,
    category: string,
    title: string,
    author: string,
    book_object: BookObjectType
}



function BookListView(props: BookListProps){
    return (
        



        
        <div className={bookListStyle.bookList}>
            {/* <div className={bookListStyle.bookListHeaderRectangle}>
                <p className={bookListStyle.bookListHeader}>{props.title}</p>
            </div> */}
            <Link to={`/catalog/${props.category}/${props.id}`}  className={bookListStyle.bookLink}>
                <div className={bookListStyle.hover01}>
                    <figure>
                        <img    src={'/images/Books/Hi Resolution/' +  props.id + '.jpg'} 
                                className = {bookListStyle.book_img2}
                                alt={props.title + 'Cover art'} 
                                title={props.title} 
                                loading='lazy'
                                onError={({currentTarget}) => {
                                    currentTarget.onerror = null;
                                    currentTarget.alt = "This monster is missing it's image. It will be found eventually.";
                                    currentTarget.src = "/img/placeholder.svg";
                                    currentTarget.title = "Missing book cover image of " + props.title;
                                }}
                        />
                    </figure>
                </div>
            </Link>
            <div className={bookListStyle.bookInfo}>
                <Link to={`/catalog/${props.category}/${props.id}`}  className={bookListStyle.bookLink}>
                <p className={bookListStyle.bookTitle}>{props.title}</p>
                </Link>
                <p className={bookListStyle.bookAuthor}>by {props.author}</p>
                <p className={bookListStyle.bookAuthor}>Year: {props.book_object?.year}</p>
                <p className={bookListStyle.bookAuthor}>Number of monsters: {props.book_object?.monster_keys.length}</p>
                <div className={bookListStyle.bookListFooterRectangle}>
                    <p className={bookListStyle.bookListDescriptionText}>Publication ID: {props.id}</p>
                </div>

            </div>
        </div>
        
        
    )
}
  
  export default BookListView;
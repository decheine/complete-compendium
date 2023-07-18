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

import * as bookCardStyle from "@styles/modules/bookcard.module.css"

// BookCard props type
type BookCardProps = {
    id: string,
    category: string,
    title: string
}

function BookCard(props: BookCardProps){
    let image_url = '/images/Books/Hi Resolution/' +  props.id + '.jpg'
    let image_placeholder = "https://upload.wikimedia.org/wikipedia/commons/6/65/No-Image-Placeholder.svg"

    let book_image = null;
    book_image = <img    src={image_url} 
            className = {bookCardStyle.book_img2}
            alt={props.title + 'Cover art'} 
            title={props.title} 
            loading='lazy'
            onError={({currentTarget}) => {
                currentTarget.onerror = null;
                currentTarget.alt = "This monster is missing it's image. It will be found eventually.";
                currentTarget.src = image_placeholder;
                currentTarget.title = "Missing book cover image of " + props.title;
            }}/>
    return (
        

        
        <div className={bookCardStyle.bookCard}>
            <div className={bookCardStyle.bookCardHeaderRectangle}>
                <p className={bookCardStyle.bookCardHeader}>{props.title}</p>
            </div>
            <div className={bookCardStyle.book_arrow}>
                <div className={bookCardStyle.book_pointLeft}></div>
                <div className={bookCardStyle.book_line}></div>
                <div className={bookCardStyle.book_pointRight}></div>
            </div>
            {/* <Link to={`/catalog/${props.category}/${props.id}`}  className={bookCardStyle.bookLink}>
            <div className={bookCardStyle.hover14 column}>
                <figure>
                    <img className={bookCardStyle.book_img-2} src={'/images/Books/Hi Resolution/' +  props.id + '.jpg'} alt={props.title}/>
                </figure>
                </div>
            </Link> */}
            <a href={`/catalog/${props.category}/${props.id}`}  className={bookCardStyle.bookLink}>
            <div className={bookCardStyle.hover01}>
                <figure>
                    {book_image}
                </figure>
                </div>
            </a>
            <div className={bookCardStyle.group12}>
                <div className={bookCardStyle.bookCardFooterRectangle}>
                    <p className={bookCardStyle.bookCardDescriptionText}>{props.id}</p>
                </div>
            </div>
        </div>
        
        
    )
}
  
  export default BookCard;
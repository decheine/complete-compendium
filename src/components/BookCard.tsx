import React from 'react';

/**
 * 
 * @param {*} props 
 * img = path to image file
 * description = description card text
 * header = header text
 * @returns 
 */


import "./BookCard.css"

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
            className = "book_img-2"
            alt={props.title + 'Cover art'} 
            title={props.title} 
            onError={({currentTarget}) => {
                currentTarget.onerror = null;
                currentTarget.alt = "This monster is missing it's image. It will be found eventually.";
                currentTarget.src = image_placeholder;
                currentTarget.title = "Missing book cover image of " + props.title;
            }}/>
    return (
        

        
        <div className="book-card">
            <div className="book-card-header-rectangle">
                <p className="book-card-header">{props.title}</p>
            </div>
            <div className="book_arrow">
                <div className="book_point-left"></div>
                <div className="book_line"></div>
                <div className="book_point-right"></div>
            </div>
            {/* <Link to={`/catalog/${props.category}/${props.id}`}  className="book-link">
            <div className="hover14 column">
                <figure>
                    <img className="book_img-2" src={'/images/Books/Hi Resolution/' +  props.id + '.jpg'} alt={props.title}/>
                </figure>
                </div>
            </Link> */}
            <a href={`/catalog/${props.category}/${props.id}`}  className="book-link">
            <div className="hover01 column">
                <figure>
                    {book_image}
                </figure>
                </div>
            </a>
            <div className="group-1-2">
                <div className="book-card-footer-rectangle">
                    <p className="book-card-description-text">{props.id}</p>
                </div>
            </div>
        </div>
        
        
    )
}
  
  export default BookCard;
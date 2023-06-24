// Page that has all the books for a given setting


import { useState, useEffect } from "react";
import { useParams } from "react-router-dom"; 
import Layout from "../../Layout";

import MonsterList from "../../MonsterList";

import './BookPage.css'

import { GLOBALS } from '../../../data/GLOBALS';

// import GLOBALS

// Input Structure
// interface BookProps {
//     book_title: string,
//     monster_keys: Object
// }

// interface BookLoaderProps {
//     publish_id: string
// }

// Need to call API to get settings


const BookPageLoader = () => {
    const {category, publish_id} = useParams();
    const [monster_keys, setMonsters] = useState([])
    const [book_title, setTitle] = useState([])
    const [author, setAuthor] = useState([])
    const [year, setYear] = useState([])
  

    useEffect(() => {
    const fetchData = () => {
        fetch(GLOBALS.API_ENDPOINT + "/api/catalog/" + publish_id)
            .then(response => {
                // console.log("response", response.json());
            return response.json()
            })
            .then(data => {
                // console.log("book data: ", data[0]);
                // console.log("monster_keys: ", data[0].monster_keys)
                setMonsters(data[0].monster_keys);
                setTitle(data[0].title);
                setAuthor(data[0].author);
                setYear(data[0].year);
            })
        }
      fetchData()
    }, [publish_id])

    let image_placeholder = "https://upload.wikimedia.org/wikipedia/commons/6/65/No-Image-Placeholder.svg"
  
    return (
        <>
        <div className="background"></div>
        <Layout>
            {/* Background Image Paper */}
            
            {/* Image */}
            <div className="frame">
                <div className="card-1">
                    <div className="col-1">
                        <img src={'/images/Books/Hi Resolution/' +  publish_id + '.jpg'} className="card-img"
                        alt="Book Cover (alt text coming soon)"
                        onError={({currentTarget}) => {
                            currentTarget.onerror = null;
                            currentTarget.alt = "This monster is missing it's image. It will be found eventually.";
                            currentTarget.src = image_placeholder;
                            currentTarget.title = "Missing book cover image of " + book_title;
                        }}/>
                    </div>
                    <div className="col-2">
                        <h5 className="card-title">{book_title}</h5>
                        <div className="card-body">
                            <div className="card-text">
                                <ul>
                                    <li>
                                        <strong>Author:</strong>  {author}
                                    </li>
                                    <li>
                                        <strong>Year:</strong> {year}
                                    </li>
                                    <li>
                                        <strong>Monster Count:</strong> {monster_keys.length}
                                    </li>
                                </ul>
                            </div>
                        </div>
                    </div>
                </div>
            </div>

            {/* Monster List */}
            <h3>Monsters</h3>
            <MonsterList monster_keys={monster_keys} url_suffix={'/catalog/' + category + "/" + publish_id + "/"}/>
        </Layout>
        </>
    )
  }


export default BookPageLoader;
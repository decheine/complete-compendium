// Page that has all the books for a given setting


import { Link, useParams } from "react-router-dom"; 
import Layout from "../../Layout";

import { BookList } from "./BookList";
import './SettingPage.css'
const ACRONYMS = require('../../../data/CatAcronyms.json')

// Input Structure
interface CategoryProps {
    category: string
}

// Need to call API to get settings

function SettingPage() {
    let { category } = useParams();
    // const the_category = props.category;
    if(category === undefined){
        return (
            <>
            </>
        )
    } else {
        console.log("setting acronym: ", category)
        return (
            <>
                <Layout>

                    <div className="setting-logo">
                        <img className="headerimg" src={'/images/grf/' +  category + '.gif'} alt={category + 'category image'}></img>

                    </div>
                    
                    <div className="categoryBody"></div>
                    <BookList category={category}/>
                </Layout>
            </>
        )
        
    }
}

export default SettingPage;
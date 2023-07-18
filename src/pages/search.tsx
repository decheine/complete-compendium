import React from "react"

import ZoomImage from '../components/ZoomImage';
import TableOfContents from '../components/TableOfContents';

import './about.css';
import Layout from "../components/Layout";
import { Link } from "gatsby";

export function searchPage() {
    if(typeof document !== 'undefined'){
        document.title = "Complete Compendium - About"
    }
    return (
        // upper page with category links
    <>
    <Layout>
        <div className="about-wrapper">
        <main>
            <h1>Search</h1>
            <em>
            Search functionality is offline until I can figure out how to do it statically, without dedicated servers.
            <br/>
            Tip: Ctrl+F on the <Link to="/appendix">Appendix</Link> page works fairly well.
            </em>
            

        </main>
        </div>
    </Layout>
            
    </>

        // lower page with all book list
    );
}

export default searchPage;
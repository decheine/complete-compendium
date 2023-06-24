import React from 'react'

import './catalog.css'

import { CategoriesList } from '../components/CategoriesList';
import { AllBooksList } from '../components/AllBooksList';
import NavBar from "../components/Navbar"

export function catalog() {
    document.title = "Catalog - Complete Compendium"
    return (
        // upper page with category links
      <>
      {/* <Layout> */}
      <NavBar/>
        <div className='background-catalog'>
          <h2 className='catalog-title' id='settings'>All Campaign Settings</h2>
          <div className="CatalogDescription">
              Browse monster books by setting or browse all at once.
          </div>
          <CategoriesList/>
          {/* All Books */}
          <h2 className="catalog-title" id='books'>All Books</h2>
          <AllBooksList/>
        </div>
      {/* </Layout> */}
      </>
      // lower page with all book list
    );
}
export default catalog;
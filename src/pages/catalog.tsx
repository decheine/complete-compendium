import React from 'react'
import Layout from '../components/Layout';

import { CategoriesList } from '../components/CategoriesList';
import { AllBooksList } from '../components/AllBooksList';

import * as catalogStyle from '@styles/modules/catalog.module.css'
import { HeadProps } from 'gatsby';

type DataProps = {
  site: {
    siteMetadata: {
      title: string
    }
  }
}

export function catalog() {
    if(typeof document !== 'undefined'){
      document.title = "Catalog - Complete Compendium"
    }
    return (
        // upper page with category links
      <>
      <Layout url='/catalog'>
      {/* <NavBar/> */}
        <div className='backgroundCatalog'>
          <h2 className='catalogTitle' id='settings'>All Campaign Settings</h2>
          <div className={catalogStyle.CatalogDescription}>
              Browse monster books by setting or browse all at once.
          </div>
          <CategoriesList/>
          {/* All Books */}
          <h2 className={catalogStyle.catalogTitle} id='books'>All Books</h2>
          <AllBooksList/>
        </div>
      </Layout>
      </>
      // lower page with all book list
    );
}
export default catalog;

export function Head(props: HeadProps<DataProps>) {
  return (
    <>
    <title>Catalog - AD&D 2e Complete Compendium</title>
    
    </>
  )
}
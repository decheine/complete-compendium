import React from "react"

import Navbar from "./Navbar";
import BreadCrumb from "./BreadCrumb";
// import './Layout.css'
import * as layoutStyle from '@styles/modules/layout.module.css'

import Footer from "./Footer";
/**
 * 
 * @param param0 
 * @returns 
 * 
 * 
 * 
 * 
 */

const Layout = ({ children } :any) => {
    const url = typeof window !== 'undefined' ? window.location.pathname : '';
    // console.log("Layout: ")
    // split path
    const relative_locs = url.split("/")
    relative_locs.pop();
    relative_locs.shift();
    // console.log(relative_locs)
    return (
      <div className={layoutStyle.layoutWrapper}>
        <Navbar/>
        <div className={layoutStyle.layout}>
        <BreadCrumb path={relative_locs}/>
          {/* {pathname !== "/" ? <BreadCrumb title={breadCrumbs[1]} setting={breadCrumbs[2]} book={breadCrumbs[3]} monster_key={breadCrumbs[4]}/> : null} */}
          {children}
        </div>
        <Footer/>
      </div>
    );
};





  

  export default Layout
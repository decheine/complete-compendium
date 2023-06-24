import React from "react"

import BreadCrumb from "../components/BreadCrumbFrame";
import Footer from "./Footer";
import Navbar from "./Navbar";
import './Layout.css'

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
    console.log("Layout: ")
    return (
      <div className="layout-wrapper">
        <Navbar/>
        <div className="layout">
          {/* {pathname !== "/" ? <BreadCrumb title={breadCrumbs[1]} setting={breadCrumbs[2]} book={breadCrumbs[3]} monster_key={breadCrumbs[4]}/> : null} */}
          {children}
        </div>
      </div>
    );
};





  

  export default Layout
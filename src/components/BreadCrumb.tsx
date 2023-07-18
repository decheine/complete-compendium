import React from "react"
import { Link } from "gatsby"

/**
 * Breadcrum react component that displays the current page's breadcrumb
 * Showing Catalog > Setting > Book
 */

// Breadcrum react component that displays the current page's breadcrumb showing Catalog > Setting > Book
import * as breadcrumbStyle from "@styles/modules/breadcrumb.module.css"

// import { title } from 'process';
const Acronyms = require('@data/AcronymsSetting.json')
const KeyToTitles = require('@data/AA_KEYS_TITLES.json')
const BooksIDToTitles = require('@data/sortedtsr.json')
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome'
import { library, dom } from '@fortawesome/fontawesome-svg-core'
import {
    faCoffee,
    faAddressBook,
    faAirFreshener,
    faAmbulance,
    faAtom,
    faBus,
    faCoins,
    faDice,
    faAngleRight
  } from '@fortawesome/free-solid-svg-icons'
// class BreadCrumbElement extends React.Component {

function BreadCrumbElement (props: {link: string, text: string}) {
    return (
        <>
        <Link to={props.link} className='bc-element'>
            {
            props.text
           }
        </Link>
        </>
    )
}

// Specify types for Props and State
type MyProps = {
    path: string[]
}



// 👇️ we set the props to empty object, and set the state to {value: string}
const BreadCrumb = ( props: MyProps) => {
    var builtBC: any = [];
    var path = ""
    var path_count = 0;
    var text = ""
    
    var path_origin = props.path[0]

    props.path.forEach(node => {

        switch (path_origin){
            case "appendix":
                switch (path_count) {
                    case 0:
                        text = node
                        break;
                    case 1: // Monster title
                        text = KeyToTitles[node]
                        break;
                    default:
                        text = "Appendix"
                }
                break;
            case "catalog":
                switch(path_count) {
                    case 0: // Catalog
                        text = node
                        break;
                    case 1: // Setting
                        text = Acronyms[node]
                        break;
                    case 2: // Book
                        text = BooksIDToTitles[node]
                        break;
                    case 3: // Monster
                        text = KeyToTitles[node]
                        break;
                    default:
                        text= "Catalog"
                }

                break;
            case "about":
                switch(path_count){
                    case 0:
                        text = node
                        break;
                    default:
                        text = "About"
                }

                break;
        }

        path += `/${node}`

        if(path_count != 0){
            builtBC.push(
                <div className={breadcrumbStyle.arrowBox} key={`arrow-${node}`}>
                    <FontAwesomeIcon icon={faAngleRight} className={breadcrumbStyle.rightArrow} />
                </div>
            )
        }
        builtBC.push(
        
            // <div className={breadcrumbStyle.breadcrumb} key={node}>
                <Link className={breadcrumbStyle.bcElement} to={path} key={node}>{text} </Link>
            )
        // builtBC.push(
        //     <FontAwesomeIcon icon="angle-right" className='right-arrow' />
        // )
        path_count++
    }
    )
    // <div className={breadcrumbStyle.bcElement}>{x}</>



    return (
        <div className={breadcrumbStyle.bcFrame}>
            {/* {props.path} */}
            <div className={breadcrumbStyle.startCap}/>
            {builtBC}
            <div className={breadcrumbStyle.bcBg}/>
        </div>
    )
}

export default BreadCrumb;


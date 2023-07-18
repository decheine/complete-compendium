import React, { useState, useEffect } from 'react';

// import { library } from '@fortawesome/fontawesome-svg-core'
// import { fas } from '@fortawesome/free-solid-svg-icons'
// import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
// import { faBars } from '@fortawesome/free-solid-svg-icons'
import './Navbar.css';
// import * as navbarStyle from '@styles/modules/navbar.module.css';
// import './Sidebar.css';

// library.add(fas, faBars)


// Reimpliment NavBar as React component


// Sidebarprops type
// type SidebarProps = {
//     sidebarOpen: boolean,
//     closeSidebar: () => void
// }

// // Boolean class that renders depending on true or false
// class BooleanDisplay extends React.Component<SidebarProps> {

//     // constructor(props: SidebarProps) {
//     //     super(props);
//     //     // Don't call this.setState() here!
//     //     // this.state = { sidebarOpen: 0 };
//     //     // this.handleClick = this.handleClick.bind(this);
//     // }

//     render() {
//       console.log(this.props.sidebarOpen)
//         return (
//             <div>
//                 {this.props.sidebarOpen ? "Open" : "Closed"}
//             </div>
//         )
//     }
// }

function Navbar() {
    const [click, setClick] = useState(false);
    const [button, setButton] = useState(true);

    const check = [
      {id: "hamberger-input", checked: 0}
    ]

    // const [checkedList, setCheckedList] = React.useState(
    //   check.map(x => !!x.checked)
    // );

    //  const overlay_checkbox = (
    //   <>
    //     <input type="checkbox" id="hamburger-input" className="burger-shower" />
    //   </>
    // )

    // console.log(button)
    const handleClick = () => {
      // Set "checked" status of checkbox to opposite of click
      setClick(!click);
      const checkbox = document.getElementById("hamburger-input") as HTMLInputElement;
      checkbox.checked = !click;
    }
    const closeMobileMenu = (e: any) => {
      // e.preventDefault();
      // console.log(e.target);
      // e.stopPropagation()
      // setClick(!click); 
      console.log("closeMobileMenu");
      // (overlay_checkbox.checked = false;
    };
    // displays on mobile
    const showButton = () => {
        if (window.innerWidth <= 700) {
            setButton(false);
        } else {
            setButton(true);
        }
    };

    useEffect(() => {
        showButton();
    }, []);

    if(typeof window !== 'undefined'){
      window.addEventListener('resize', showButton);
    }
    if(!button){
        return (
            <div className="navbar-container" >
            <div className="menu-mobile">
                <a href='/' className='navbar-logo'  >
                    Home    
                </a>
                {/* {overlay_checkbox} */}
                <input type="checkbox" id="hamburger-input" className="burger-shower" onClick={handleClick}/>
                {check.map((item, idx) => (
                  
                  <label id="hamburger-menu" htmlFor="hamburger-input" key="key">
                    <nav id="sidebar-menu">
                      <h3>Menu</h3>
                      <ul>
                        <label className='nav-item' onClick={handleClick}>
                            <a href='/' className='nav-links'>
                                Home
                            </a>
                        </label>
                        <li className='nav-item'>
                            <a href='/appendix' className='nav-links' onClick={handleClick}>
                                Appendix
                            </a>
                        </li>
                        <li className='nav-item'>
                          <a href='/catalog'
                            className='nav-links'
                            onClick={handleClick}
                          >
                            Catalog
                          </a>
                        </li>
                        <li className='nav-item'>
                          <a href='/about'
                            className='nav-links'
                            onClick={handleClick}
                          >
                            About
                          </a>
                        </li>
                        <li className='nav-item'>
                          <a href='/search'
                            className='nav-links'
                            onClick={handleClick}
                          >
                            Search &nbsp;  
                            {/* <FontAwesomeIcon icon="search" /> */}
                          </a>
                        </li>
                      </ul>
                    </nav>
                  </label>
                ))}
                
                <label className="overlay" htmlFor='hamburger-input'></label>
            </div>
            </div>
        )
    } else {
        return (
            <>
            <div className="navbar">
              <div className="navbar-wrapper">
                <a href='/' className='navbar-logo'>
                  Home
                  
                </a>
                <ul className='nav-menu'>
                  <li className='nav-item'>
                    <a href='/appendix' className='nav-links' onClick={closeMobileMenu}>
                      Appendix
                    </a>
                  </li>
                  <li className='nav-item'>
                    <a href='/catalog'
                      className='nav-links'
                      // onClick={closeMobileMenu}
                    >
                      Catalog
                    </a>
                  </li>
                  <li className='nav-item'>
                    <a href='/about'
                      className='nav-links'
                      // onClick={closeMobileMenu}
                    >
                      About
                    </a>
                  </li>
                  <li className='nav-item'>
                    <a href='/search'
                      className='nav-links'
                      // onClick={closeMobileMenu}
                    >
                      Search &nbsp;  
                      {/* <FontAwesomeIcon icon="search" /> */}
                    </a>
                  </li>
      
                </ul> 
              </div>
            </div>
            </>
        )
    }
}

export default Navbar
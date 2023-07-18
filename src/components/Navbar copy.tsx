import React, { useState, useEffect } from 'react';

// import { library } from '@fortawesome/fontawesome-svg-core'
// import { fas } from '@fortawesome/free-solid-svg-icons'
// import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
// import { faBars } from '@fortawesome/free-solid-svg-icons'
// import './Navbar.css';
import * as navbarStyle from '@styles/modules/navbar.module.css';
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
            <div className={navbarStyle.navbarContainer} >
            <div className={navbarStyle.menuMobile}>
                <a href='/' className={navbarStyle.navbarLogo}  >
                    Home    
                </a>
                {/* {overlay_checkbox} */}
                <input type="checkbox" id="hamburger-input" className="burger-shower" onClick={handleClick}/>
                {check.map((item, idx) => (
                  
                  <label id="hamburger-menu" htmlFor="hamburger-input" key="key">
                    <nav id="sidebar-menu">
                      <h3>Menu</h3>
                      <ul>
                        <label className={navbarStyle.navItem} onClick={handleClick}>
                            <a href='/' className={navbarStyle.navLinks}>
                                Home
                            </a>
                        </label>
                        <li className={navbarStyle.navItem}>
                            <a href='/appendix' className={navbarStyle.navLinks} onClick={handleClick}>
                                Appendix
                            </a>
                        </li>
                        <li className={navbarStyle.navItem}>
                          <a href='/catalog'
                            className={navbarStyle.navLinks}
                            onClick={handleClick}
                          >
                            Catalog
                          </a>
                        </li>
                        <li className={navbarStyle.navItem}>
                          <a href='/about'
                            className={navbarStyle.navLinks}
                            onClick={handleClick}
                          >
                            About
                          </a>
                        </li>
                        <li className={navbarStyle.navItem}>
                          <a href='/search'
                            className={navbarStyle.navLinks}
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
                
                <label className={navbarStyle.overlay} htmlFor='hamburger-input'></label>
            </div>
            </div>
        )
    } else {
        return (
            <>
            <div className={navbarStyle.navbar}>
              <div className={navbarStyle.navbarWrapper}>
                <a href='/' className={navbarStyle.navbarLogo}>
                  Home
                  
                </a>
                <ul className={navbarStyle.navMenu}>
                  <li className={navbarStyle.navItem}>
                    <a href='/appendix' className={navbarStyle.navLinks} onClick={closeMobileMenu}>
                      Appendix
                    </a>
                  </li>
                  <li className={navbarStyle.navItem}>
                    <a href='/catalog'
                      className={navbarStyle.navLinks}
                      // onClick={closeMobileMenu}
                    >
                      Catalog
                    </a>
                  </li>
                  <li className={navbarStyle.navItem}>
                    <a href='/about'
                      className={navbarStyle.navLinks}
                      // onClick={closeMobileMenu}
                    >
                      About
                    </a>
                  </li>
                  <li className={navbarStyle.navItem}>
                    <a href='/search'
                      className={navbarStyle.navLinks}
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
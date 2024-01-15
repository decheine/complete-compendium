import React, { useState, useEffect, useRef } from 'react';

// import { library } from '@fortawesome/fontawesome-svg-core'
// import { fas } from '@fortawesome/free-solid-svg-icons'
// import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
// import { faBars } from '@fortawesome/free-solid-svg-icons'
import './Navbar.css';
import { Link } from 'gatsby';
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
    const [button, setButton] = useState(false);

    var initialWidth = 1920
    var initialHeight = 1080
    if(typeof window !== 'undefined'){
      initialWidth = window.innerWidth
      initialHeight = window.innerHeight
    }

    const [windowSize, setWindowSize] = useState([
      initialWidth,
      initialHeight,
    ]);

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
      // Width: {windowSize[0]}
        if (windowSize[0] <= 700) {
          if(!button){
            setButton(true);
            console.log("short set show button to ", button, windowSize[0])
          }
        } else {
          if(button){
            setButton(false);
            console.log("wide setshow button to ", button, windowSize[0])
          }
        }
    };

//     const useWindowSize = (initialState = "100%", { ttl = 100 } = {}) => {
//   // initialState is used before the component mounts client-side
//   const [height, setHeight] = useState(initialState)

//   useEffect(() => {
//     const calculateHeight = debounce(() => {
//       setHeight(window.innerHeight)
//     }, ttl)

//     calculateHeight()
//     window.addEventListener("resize", calculateHeight)

//     return () => {
//       // deregister event listener on component dismount
//       window.removeEventListener("resize", calculateHeight)
//     }
//   }, [ttl])

//   return height
// }

    useEffect(() => {
      const handleWindowResize = () => {
        if(typeof window !== 'undefined'){
          setWindowSize([window.innerWidth, window.innerHeight]);
        }
        // if (windowSize[0] <= 700) {
        //   if(!button){
        //     setButton(true);
        //     console.log("short set show button to ", button, windowSize[0])
        //   }
        // } else {
        //   if(button){
        //     setButton(false);
        //     console.log("wide setshow button to ", button, windowSize[0])
        //   }
        // }
      };
      
      if(typeof window !== 'undefined'){
        window.addEventListener('resize', handleWindowResize);
      }
      
      return () => {
        if(typeof window !== 'undefined'){
          window.removeEventListener('resize', handleWindowResize);
        }
      };
    }, []);
    
    useEffect(() => {
      if (windowSize[0] <= 700) {
        // if(!button){
          setButton(true);
          // console.log("short set show button to ", button, windowSize[0])
        // }
      } else {
        // if(button){
          setButton(false);
          // console.log("wide setshow button to ", button, windowSize[0])
        // }
      }
    }, [windowSize[0]])

    // if(typeof window !== 'undefined'){
    //   window.addEventListener('resize', showButton);
    // }
    if(button){
        return (
            <div className="navbar-container" >
            <div className="menu-mobile">
                <Link to='/' className='navbar-logo'  >
                    Home
                </Link>
                {/* {overlay_checkbox} */}
                <input type="checkbox" id="hamburger-input" className="burger-shower" onClick={handleClick}/>
                {check.map((item, idx) => (
                  
                  <label id="hamburger-menu" htmlFor="hamburger-input" key="key">
                    <nav id="sidebar-menu">
                      <h3>Menu</h3>
                      <ul>
                        <label className='nav-item' onClick={handleClick}>
                            <Link to='/' className='nav-links'>
                                Home
                            </Link>
                        </label>
                        <li className='nav-item'>
                            <Link to='/appendix' className='nav-links' onClick={handleClick}>
                                Appendix
                            </Link>
                        </li>
                        <li className='nav-item'>
                          <Link to='/catalog'
                            className='nav-links'
                            onClick={handleClick}
                          >
                            Catalog
                          </Link>
                        </li>
                        <li className='nav-item'>
                          <Link to='/about'
                            className='nav-links'
                            onClick={handleClick}
                          >
                            About
                          </Link>
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
                <Link to='/' className='navbar-logo'>
                  Home
                </Link>
                <ul className='nav-menu'>
                  <li className='nav-item'>
                    <Link to='/appendix' className='nav-links'>
                      Appendix
                    </Link>
                  </li>
                  <li className='nav-item'>
                    <Link to='/catalog' className='nav-links'>
                      Catalog
                    </Link>
                  </li>
                  <li className='nav-item'>
                    <Link to='/about'
                      className='nav-links'
                      // onClick={closeMobileMenu}
                    >
                      About
                    </Link>
                  </li>
                </ul> 
              </div>
            </div>
            </>
        )
    }
}

export default Navbar
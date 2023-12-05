// Footer component

import React from 'react';
import './Footer.css';
import { Link } from 'gatsby';

function Footer() {
    return (
        <div className="footer">
            <div className="footer-container">
                <div className="paragraph">
                    <p>
                    All content herein was harvested from the Wayback Machine's archive of the website lomion.de/. Any and all intellectual property mentioned is property of TSR inc. (Wizards of the Coast). This site is for historical and encyclopedic purposes only. This site has no revenue of any sort and I seek to take no profit from the intellectual property of the original authors. 
                    </p>
                </div>
                <div className="footer-links">
                    <div className="footer-link-wrapper">
                        <div className="links-title">
                            Pages
                        </div>
                        <div className="footer-link-items">
                            <Link to="/appendix">Appendix</Link>
                            <Link to="/catalog">Catalog</Link>
                            <Link to="/about">About</Link>
                        </div>
                    </div>
                </div>
            </div>
            <div className="bottom-banner">
                <hr className="footer-hr" />
                <div className="bottom-banner-text">
                    <p>All Rights of intellectual property to TSR inc. (Wizards of the Coast).</p>
                </div>
            </div>
        </div>
    );
}

export default Footer;
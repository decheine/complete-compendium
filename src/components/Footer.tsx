// Footer component

import React from 'react';
import './Footer.css';
import { Link } from 'gatsby';

function Footer() {
    return (
        <div className="footer">
            <div className="footer-container">
                <div className="paragraph">
                    <p>Advanced Dungeons and Dragons 2nd Edition Complete Compendium.</p>
                    <p>
                    All intellectual property mentioned is the intellectual property of TSR inc. (Wizards of the Coast). This site is for archival and encyclopedic purposes only. 
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
                            <Link to="/about/the-monsters">How To Use This Book</Link>
                            <Link to="/table">Table</Link>
                            <a href="https://ko-fi.com/novicewizard" target="_blank">Donate</a>
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
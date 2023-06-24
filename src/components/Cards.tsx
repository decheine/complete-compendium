// Cards component with 3 HomeCards
//

import React from 'react';

import { HomeCard } from './HomeCard';

import './Cards.css';

export function Cards() {
    return (
        <div className="Cards">
            <div className="card-row">
                <HomeCard   title="Every Monster" 
                            body="Compiled from every sourcebook, every monster with a page in any AD&D 2nd Edition source material is indexed." 
                            linkText="See the Complete Appendix" 
                            link="/appendix" />

                <HomeCard   title="Every Setting" 
                            body="This compendium contains every campaign setting from Forgotten Realms to the obscure Alternity. The Mists of Ravenloft to Castle Greyhawk to the great city of Cigil at the center of the Cosmos." 
                            linkText="See Every Campaign Setting" 
                            link="/catalog#settings" />

                <HomeCard   title="Every Book" 
                            body="Every publication id number mentioned across all the monster files has been collected and cataloged. " 
                            linkText="See Every Monster Sourcebook" 
                            link="/catalog#books" />
            </div>
        </div>
    );
}
import React from "react"
import Layout from "@components/Layout";
import { HeadProps, Link } from "gatsby";

type DataProps = {
    site: {
      siteMetadata: {
        title: string
      }
    }
  }
  
  const headerStyle = {
    color: "#1250A2",
    marginTop: "12px",
    marginRight: "0px",
    marginLeft: "0px",
    marginBottom: "0px",
    fontFamily: "frizquadrata_ltbold",
    letterSpacing: "0.3px",
    width: "100%"
  }

  const hr1Style = {
    color: "black",
    backgroundColor: "black",
    height: "1mm",
    marginTop: "1px",
    width: "100%"
  }

  const hr2Style = {
    backgroundColor: "#1250A2",
    height: "2mm",
    marginTop: "3mm",
    marginBottom: "7px"
  }

  const hrBottomStyle = {
    color: "gray",
    height: "1px",
  }

export function themonsters() {
    // if(typeof document !== 'undefined'){
    //     document.title = "Complete Compendium - About"
    // }
    return (
        // upper page with category links
    <>
    <Layout url='/about/the-monsters'>
        <main>
        <h1 style={headerStyle}>How To Use This Book</h1>
        <hr style={hr1Style}/>
        <hr style={hr2Style}/>
            
            <p>The thoughtful creativity of the authors allows for these monsters to be readily adapted to many other TTRPGs that have a similar combat system to AD&D 2nd Edition.</p>
            <p><b>Adapting to D&D 5th Edition</b> Many 5th Edition monsters can trace their origins to the monsters laid out here. I've found using the detailed Habitat/Society and Ecology sections to be invaluable supplemental material to the modern iterations. Combat can also provide tactics in detail.</p>
            
            <p>The most apparent combat differences between 2nd Edition and 5th Edition are only THAC0 and Armor Class, which are very easy to convert to 5th Edition. 2nd Edition AC counts down from 20, 5th counts up from 10. 2nd Edition THAC0 counts down from 20. So to get the 5th Edition AC, subtract the 2e AC from 20, and to get the 5th Edition to hit bonus, subtract the THAC0 from 20. Lastly you can add +1 or +2 to AC and to-hit to account for the scaling difference between 2e and 5e. For example, the <Link to="/appendix/aboleth">aboleth</Link> has THAC0 of 13 and an AC of 4. Therefore a 5th Edition conversion would give it an AC of 16 and +7 to hit. The 5e aboleth has an AC of 17 and +9 to hit.</p>
            
            <p>Saving throws, however, do not translate at all so you will have to come up with a realistic save and DC based on your judgement of the spell or ability.</p> 

            <blockquote>The following text is taken mostly from the <i>AD&D 2nd Edition Monsterous Manual</i> (<a href="/catalog/add2_01/2140/">2140</a>).  
            </blockquote>
            <p className="f">Each monster is described fully, with entries that describe behavior, combat modes, and so on. These are explained in the following text.</p>
            <p className="f"><b>Climate/Terrain</b> defines where the creature is most often found. Climates include arctic, sub-arctic, temperate, and tropical. Typical terrain includes plain/scrub, forest, rough/hill, mountain, swamp, and desert. In some cases, a range is given; for instance, <q>cold</q> implies arctic, sub-arctic, and colder temperate regions.</p>
            <p className="f"><b>Frequency </b>is the likelihood of encountering a creature in an area. Chances can be adjusted for special areas.</p>
            <ul>
            <li>Very Rare = 4% chance</li>
            <li>Rare = 11% chance</li>
            <li>Uncommon = 20% chance</li>
            <li>Common = 65% chance</li>
            </ul>
            <p className="f"><b>Organization</b> is the general social structure the monster adopts. &ldquo;Solitary&rdquo; includes small family groups.</p>
            <p className="f"><b>Activity Cycle</b> is the time of day when the monster is most active. Those active at night can be active at any time in subterranean settings. These are general guidelines and exceptions are fairly common.</p>
            <p className="f"><b>Diet</b> shows what the creature usually eats. Carnivores eat meat, herbivores eat plants, and omnivores eat either. Scavengers primarily eat carrion. If a monster does not fit any of these categories, the substances it does eat are described in the entry or in the text.</p>
            <p className="f"><b>Intelligence</b> is the equivalent of human <q>IQ</q>. Certain monsters are instinctively cunning; these are noted in the monster descriptions. Ratings correspond roughly to the following Intelligence ability scores:</p>
            <ul>
            <li>0 &ndash; Nonintelligent or not ratable</li>
            <li>1 &ndash; Animal intelligence</li>
            <li>2-4 &ndash; Semi-intelligent</li>
            <li>5-7 &ndash; Low intelligence</li>
            <li>8-10 &ndash; Average (human) intelligence</li>
            <li>11-12 &ndash; Very intelligent</li>
            <li>13-14 &ndash; Highly intelligent</li>
            <li>15-16 &ndash; Exceptionally intelligent</li>
            <li>17-18 &ndash; Genius</li>
            <li>19-20 &ndash; Supra-genius</li>
            <li>21+ &ndash; Godlike intelligence</li>
            </ul>
            <p className="f"><b>Treasure</b> refers to the treasure tables in the <i>Dungeon Master's Guide</i>. If individual treasure is indicated, each individual may carry it (or not, at the DM's discretion). Major treasures are usually found in the monster's lair; these are most often designed and placed by the DM. Intelligent monsters will use the magical items present and try to carry off their most valuable treasures if hard pressed. If treasure is assigned randomly, roll for each type possible; if all rolls fail, no treasure of any type is found. Treasure should be adjusted downward if a few monsters are encountered. Large treasures are noted by a multiplier (&times;10, for example); this should not be confused with treasure type X. Treasure types listed in parentheses are treasures found in the creatures' lair. Do not use the tables to place dungeon treasure, since the numbers encountered underground will be much smaller.</p>
            <p className="f"><b>Alignment</b> shows the general behavior of the average monster of that type. Exceptions, though uncommon, may be encountered.</p>
            <p className="f"><b>No. Appearing</b> indicates an average encounter size for a wilderness encounter. The DM should alter this to fit the circumstances as the need arises. This should not be used for dungeon encounters.</p>
            <p>Note that some solitary creatures are found in small groups; this means they are found in very small family units, or that several may happen to be found together, but do not cooperate with one another.</p>
            <p className="f"><b>Armor className</b> is the general protection worn by humans and humanoids, protection due to physical structure or magical nature, or difficulty in hitting due to speed, reflexes, etc. Humans and humanoids of roughly man-size that wear armor will have an unarmored rating in parentheses. Listed AC does not include any special bonuses noted in the description.</p>
            <p className="f"><b>Movement</b> shows the relative speed rating of the creature. Higher speeds may be possible for short periods. Human, demihuman, and humanoid movement rate is often determined by armor type (unarmored rates are given in parentheses). Movements in different mediums are abbreviated as follows:</p>
            <ul>
            <li>Fl = flying</li>
            <li>Sw = swimming</li>
            <li>Br = burrowing</li>
            <li>Cl = climbing</li>
            <li>Wb = moving across webs</li>
            <li>Jp = jumping</li>
            </ul>
            <p>Flying creatures also have a Maneuverability className from A to E. className A creatures have virtually total command over their movements in the air; they can hover, face any direction in a given round, and attack each round. className B creatures are very maneuverable; they can hover, turn 180 degrees in a round, and attack in each round. className C creatures are somewhat agile in the air; they cannot move less than half their movement rate without falling, they can turn up to 90 degrees in a round, and attack aerially once every two rounds. className D creatures are somewhat slow; they cannot move less than half their movement rate without falling, can turn only 60 degrees in a round, and can make a pass once every three rounds. className E includes large, clumsy fliers; these cannot move less than half their movement rate without falling, can turn only 30 degrees in a round, and they can make one pass every six rounds. See Chapter 9 of the <i>DMG</i> for more information.</p>
            <p className="f"><b>Hit Dice</b> controls the number of hit points damage a creature can withstand before being killed. Unless otherwise stated, Hit Dice are 8-sided (1-8 hit points). The Hit Dice are rolled and the numbers shown are added to determine the monster's hit points. Some monsters have a hit point spread instead of Hit Dice, and some have additional points added to their Hit Dice. Thus, a creature with 4+4 Hit Dice has 4d8+4 hit points (8-36 total). Note that creatures with +3 or more hit points are considered the next higher Hit Die for purposes of attack rolls and saving throws.</p>
            <p className="f"><b>THAC0</b> is the attack roll the monster needs to hit Armor className 0. This is always a function of Hit Dice, except in the case of very large, nonaggressive herbivores (such as some dinosaurs), or creatures which have certain innate combat abilities. A human or demihuman always uses a player character THAC0, regardless of whether they are player characters or <q>monsters</q>. The THAC0 does not include any special bonuses noted in the descriptions.<a href="#footnote-1">[*]</a></p>
            <p className="f"><b>No. of Attacks</b> shows the basic attacks the monster can make in a melee round, excluding special attacks. This number can be modified by hits that sever members, spells such as haste and slow, and so forth. Multiple attacks indicate several members, raking paws, multiple heads, etc.</p>
            <p className="f"><b>Damage/Attack</b> shows the amount of damage a given attack causes, expressed as a spread of hit points (based on a die roll or combination of die rolls). If the monster uses weapons, the damage done by the typical weapon will be allowed by the parenthetical note <q>weapon</q>. Damage bonuses due to Strength are listed as a bonus following the damage range.</p>
            <p className="f"><b>Special Attacks</b> detail attack modes such as dragon breath, magic use, etc. These are explained in the monster description.</p>
            <p className="f"><b>Special Defenses</b> are precisely that, and are detailed in the monster description.</p>
            <p className="f"><b>Magic Resistance</b> is the percentage chance that any magic cast upon the creature will fail to affect it, even if other creatures nearby are affected. If the magic penetrates the resistance, the creature is still entitled to any normal saving throw allowed. Creatures may have resistances to certain spells; this is not considered <q>magic resistance</q>, which is effective against all spells.</p>
            <p className="f"><b>Size</b> is abbreviated as</p>
            <ul>
            <li>T = tiny (2' tall or less);</li>
            <li>S = smaller than a typical human (2+' to 4');</li>
            <li>M = man-sized (4+' to 7');</li>
            <li>L = larger than man-sized (7+' to 12');</li>
            <li>H = huge (12+' to 25'); and</li>
            <li>G = gargantuan (25+').</li>
            </ul>
            <p>Most creatures are measured in height or length; some are measured in diameter. Those measured in diameter may be given a different size category than indicated above. For instance, while a 6-foot tall humanoid is considered size M, a spherical creature 6 feet in diameter has much more mass, so is considered size L. Similarly, a creature 12 feet long with a very slender body (like a snake) might be considered only man-sized. Adjustments like these should not move a creature more than one size category in either direction.</p>
            <p className="f"><b>Morale</b> is a general rating of how likely the monster is to persevere in the face of adversity or armed opposition. This guideline can be adjusted for individual circumstances. Morale ratings correspond to the following range:</p>
            <ul>
            <li>2-4 Unreliable</li>
            <li>5-7 Unsteady</li>
            <li>8-10 Average</li>
            <li>11-12 Steady</li>
            <li>13-14 Elite</li>
            <li>15-16 Champion</li>
            <li>17-18 Fanatic</li>
            <li>19-20 Fearless</li>
            </ul>
            <p className="f"><b>XP Value</b> is the number of experience points awarded for defeating, but not necessarily killing, the monster. This value is a guideline that can be modified by the DM for the degree of challenge, encounter situation, and for overall campaign balance.</p>
            <p className="f"><b>Combat</b> is the part of the description that discusses special combat abilities, arms and armor, and tactics.</p>
            <p className="f"><b>Habitat/Society</b> outlines the monster's general behavior, nature, social structure, and goals. In some cases, it further describes their lairs (the places they live in), breeding habits, and reproduction rates.</p>
            <p className="f"><b>Ecology</b> describes how the monster fits into the campaign world, gives any useful products or byproducts, and any other miscellaneous information.</p>
            <p className="f"><b>Variations</b> of a monster are given in a special section after the main monster entry. These can be found by consulting the <a href="/appendix">appendix</a>. For instance, the <a href="/appendix/xorn">xorn</a> entry also describes the <i>xaren</i>, a very similar creature.</p>
            <p className="f"><b>Psionics</b> are mental powers possessed by many creatures in the Monstrous Manual. The psionic listings are explained below:</p>
            <div>
            <p><b>Level:</b> How tough the monster is in terms of psionic experience level.</p>
            <p><b>Dis/Sci/Dev:</b> How many disciplines the creature can access, followed by the total number of sciences and devotions the creature knows. Monsters can know sciences and devotions only from the disciplines they can access.</p>
            <p><b>Attack/Defense:</b> The telepathic attack and defense modes that the creature can use. Note that defense modes are not included in the total number of powers the creature knows. Abbreviations used are as follows:</p>
            <ul>
                <li>PB Psionic Blast</li>
                <li>M- Mind Blank</li>
                <li>MT Mind Thrust</li>
                <li>TS Thought Shield</li>
                <li>EW Ego Whip</li>
                <li>MB Mental Barrier</li>
                <li>II Id Insinuation</li>
                <li>IF Intellect Fortress</li>
                <li>PsC Psychic Crush</li>
                <li>TW Tower of Iron Will</li>
            </ul>
            <p><b>Power Score:</b> The creature's usual score when using a power that is not automatically successful.</p>
            <p><b>PSPs:</b> The creature's total pool of psionic strength points (the maximum available to it).</p>
            </div>
            <p>The rest of the listing indicates, by discipline, which powers the creature has, sometimes listing the most common powers, sometimes listing only the powers that all members of the species have. Unless otherwise noted, the creature always knows powers marked by an asterisk. For information regarding psionic powers, see PHBR5, <i>The Complete Psionics Handbook</i>. If the DM chooses not to use psionics in the campaign, the powers can be changed to magical equivalents or simply ignored, though the latter severely impedes certain monsters.</p>
            <hr style={hrBottomStyle}/>
            Archivist's footnotes:
            <p id="footnote-1">* Listed THAC0 will occasionally not include listed bonuses—<Link to="/appendix/skelwarr">skeleton warrior</Link>'s for example. Read each monster's text carefully, especially more complicated monsters.</p>
        </main>
    </Layout>
            
    </>

        // lower page with all book list
    );
}

export default themonsters;

export function Head(props: HeadProps<DataProps>) {
    return (
      <>
      <title>The Monsters - AD&D 2e Complete Compendium</title>
      
      </>
    )
  }
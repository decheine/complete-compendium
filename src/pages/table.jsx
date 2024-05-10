import React from 'react'
import Layout from '../components/Layout';


import {TabulatorFull as Tabulator} from "tabulator-tables"; //import Tabulator libraryimport { MenuModule } from 'tabulator-tables';
import "tabulator-tables/dist/css/tabulator.min.css"; //import Tabulator stylesheet

// import {MenuModule} from 'tabulator-tables';
// import {MoveColumnsModule} from 'tabulator-tables';
// import {PageModule} from 'tabulator-tables';

// import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
// import { faCheckSquare, faSquare } from '@fortawesome/free-solid-svg-icons';

const monster_data = require("@data/stats_df.json")




class MonsterTable extends React.Component {
  el = React.createRef();

  tabulator = null; 
  tableData = monster_data;

  

  componentDidMount() {

    
    //define column header menu as column visibility toggle
    var headerMenu = function(){
        var menu = [];
        var columns = this.getColumns();

        for(let column of columns){

            //create checkbox element using font awesome icons
            let icon = document.createElement("i");
            icon.classList.add("fas");
            icon.classList.add(column.isVisible() ? "fa-check-square" : "fa-square");

            //build label
            let label = document.createElement("span");
            let title = document.createElement("span");

            title.textContent = " " + column.getDefinition().title;

            label.appendChild(icon);
            label.appendChild(title);

            //create menu item
            menu.push({
                label:label,
                action:function(e){
                    //prevent menu closing
                    e.stopPropagation();

                    //toggle current column visibility
                    column.toggle();

                    //change menu item icon
                    if(column.isVisible()){
                        icon.classList.remove("fa-square");
                        icon.classList.add("fa-check-square");
                    }else{
                        icon.classList.remove("fa-check-square");
                        icon.classList.add("fa-square");
                    }
                }
            });
        }

      return menu;
    };
// (.{1,2} HD:|(\d+)(?:-| or )(\d+) HD:|) (\d+)
    const columns = [
      {title: "Key",              field: "monster_key",       visible: true,  headerFilter: true, resizable:true, headerMenu: headerMenu,
      formatter: "link", 
      formatterParams: {
        labelField: "monster_key",
        field: "",
        urlPrefix: "/appendix/",
        urlField: "monster_key",
        target: "_blank",
        }
    },
      {title: "title",            field: "title",             visible: true,  headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "statblock_title",  field: "statblock_title",   visible: true,  headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "Activity Cycle",   field: "Activity_Cycle",    visible: false, headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "Alignment",        field: "Alignment",         visible: false, headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "AC",               field: "Armor_Class",       visible: false, headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "Climate/Terrain",  field: "Climate_Terrain",   visible: true,  headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "Damage/Attack",    field: "Damage_Attack",     visible: false, headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "Diet",             field: "Diet",              visible: false, headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "Frequency",        field: "Frequency",         visible: true,  headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "HD",               field: "Hit_Dice",          visible: false, headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "Intelligence",     field: "Intelligence",      visible: false, headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "MR",               field: "Magic_Resistance",  visible: false, headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "Morale",           field: "Morale",            visible: false, headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "Movement",         field: "Movement",          visible: false, headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "No. Appearing",    field: "No_Appearing",      visible: false, headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "No. of Attacks",   field: "No_of_Attacks",     visible: false, headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "Organization",     field: "Organization",      visible: false, headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "Size",             field: "Size",              visible: false, headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "Special Attacks",  field: "Special_Attacks",   visible: false, headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "Special Defenses", field: "Special_Defenses",  visible: false, headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "THAC0",            field: "THAC0",             visible: false, headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "Treasure",         field: "Treasure",          visible: false, headerFilter: true, resizable:true, headerMenu: headerMenu},
      {title: "XP",               field: "XP_Value",          visible: true,  headerFilter: true, resizable:true, headerMenu: headerMenu, sorterParams:{
          thousandSeparator:",",
          alignEmptyValues:"bottom",
      }}
    ]

    //instantiate Tabulator when element is mounted
    this.tabulator = new Tabulator(this.el, {
      title: "Monster Statistics",
      data: this.tableData, //link data to table
      reactiveData:true, //enable data reactivity
      columns: columns,
      // autoColumns:true, //define table columns
      layout: "fitData",
      pagination:true,
      paginationSize:20,
      movableColumns: true,
      popupContainer: false,
    });
  }

  //add table holder element to DOM
  render(){
    return (<div ref={el => (this.el = el)} />);
  }
}





export function table() {

    return (
        // upper page with category links
      <>
      <link href="dist/css/tabulator.min.css" rel="stylesheet"/>
      <script type="text/javascript" src="dist/js/tabulator.min.js"></script>
      <Layout url='/table'>
      {/* <NavBar/> */}
        <div className='backgroundTable'>
          <h3>Data Table View</h3>
          <p>Filter and sort monsters by their stats.</p>
          <p>Some fields like damage/attack are not trivial to sort, and can only be sorted alphanumerically at the moment. An "average damage" field may be added in the future. More functionality and cleaner data coming soon!</p>
          <p>Show or hide columns in the column menu by clicking on any column header. There is a simple text filter in each column.</p>
          <br/>

        </div>
        <MonsterTable/>
        <div id="example-table"></div>


      </Layout>
      </>
      // lower page with all book list
    );
}
export default table;

export function Head(props) {
  return (
    <>
    <script src="https://kit.fontawesome.com/c6a77c0087.js" crossOrigin="anonymous"></script>
    <title>Data Table - AD&D 2e Complete Compendium</title>
    </>
  )
}
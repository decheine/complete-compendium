

function getMonsterDescription(monster_key: string, fullBodyString: string): string {
    let description = ""
    const regexp = /<p class=\"f\">([^<].+?)<\/p>/;
    // const regexp = /(<p class=\\"f\\">)/gm;
    // const regexp = /(<p class)/gm;
    // const regexp = /<p class=/;
    // const matches = fullBodyString.matchAll(regexp);
    const match = fullBodyString.match(regexp)
    // for (const match of fullBodyString.matchAll(regexp)) {
    //   console.log(`Match! ${match[1]}`);
    // }
    if(match !== null){
      if(match[1]){
        description = match[1]  
      }
      // console.log("Match found!")
    } 
    // console.log("Description for: ", monster_key)
    
    // Filter html blocks
    description = description.replace(/<.*?>/g, "")
    
    // console.log(description)
    return description
  }

export default getMonsterDescription;
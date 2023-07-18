
import type { GatsbyNode } from "gatsby"
import * as path from 'path'
// const path = require(`path`)


type Monster = {
  monster_key: string
}

// 'use strict'
// exports.onCreatePage = require("./src/GatsbyNode").onCreatePages


// type testDataType = {
//   id: string
//   name: string
//   data: string[]
// }

type colorDataType = {
  name: string
  tones: {
    default: string,
    light: string,
    dark: string,
    tone: string
  }
}


// Working for JS,

/*

const path = require('path')
const data = require('./src/data/colors.json')



 //@type {import('gatsby').GatsbyNode['createPages']}

exports.createPages = async ({ actions }) => {
  const { createPage } = actions

  const template = path.resolve('./src/templates/color.tsx')

  data.forEach(color_object => {
    var path = color_object.name;
    createPage({
      path,
      component: template,
      context: color_object,
      defer: true,
    })
  })

  
}

*/

export const createPages: GatsbyNode["createPages"] = async ({
  graphql,
  actions,
  createNodeId,
  createContentDigest,
}) => {
  const { createNode } = actions

  const data = require('./src/data/colors.json')


  console.log("data!")
  console.log(data)

  const colorTemplate = path.resolve('./src/templates/color.tsx')

  data.forEach((color_object: colorDataType) => {
    // const node = {
    //   ...dataMember,
    //   parent: null,
    //   children: [],
    //   id: createNodeId(`color__${dataMember.name}`),
    //   internal: {
    //     type: "colorDataType",
    //     content: JSON.stringify(dataMember),
    //     contentDigest: createContentDigest(dataMember),
    //   },
    // }
    var path = color_object.name;
    const nodePage = {
      path: color_object.name,
      id: createNodeId(`color__${color_object.name}`),
      internal: {
        type: "colorDataType",
        content: JSON.stringify(color_object),
        contentDigest: createContentDigest(color_object),
      }
    }
    createNode(nodePage)
    // createPage({
    //   path,
    //   component: template,
    //   context: color_object,
    //   defer: true,
    // })
  })


}


// type TypePost = {
//   id: string
//   title: string
//   slug: string
//   content: string
// }

// type TypeData = {
//     allPost: {
//         nodes: testDataType[]
//     }
// }

// export const createPages: GatsbyNode["createPages"] = async ( { graphql, actions } ) => {

//   const { createPage } = actions

//   const data = await graphql<TypeData>( `
//       {
//           allPost {
//               nodes {
//                   id
//                   name
//                   data {
//                     datafield1
//                     datafield2
//                   }
//               }
//           }
//       }
//       ` )

//   // Create Post Pages  
//   const postTemplate = path.resolve("./src/templates/Post.tsx")
//   const createPostPromise = data?.allPost.nodes.map((post) => {
//       createPage({
//           path : `posts/${post.slug}`,
//           component : postTemplate,
//           context : {
//               slug: post.slug,
//               // anything else you want to pass to your context
//           }
//       })
//   })

//   await Promise.all( [ createPostPromise] )
// }





// exports.createPages = ({ actions }) => {

// }

// type AllMonsters = {
//     allMonsters = {
//         nodes: Monster[]
//     }
// }


// export const sourceNodes: GatsbyNode["sourceNodes"] = async ({
//   actions,
//   createNodeId,
//   createContentDigest,
// }) => {
//   const { createNode } = actions

//   const data = require("monster.json")

//   data.forEach((monster: Monster) => {
//     const node = {
//       ...monster,
//       parent: null,
//       children: [],
//       monster_key: createNodeId(`monster__${monster.monster_key}`),
//       internal: {
//         type: "Monster",
//         content: JSON.stringify(monster),
//         contentDigest: createContentDigest(monster),
//       },
//     }

//     createNode(node)
//   })
// }


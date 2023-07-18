import * as path from "path"
import type { GatsbyNode } from "gatsby"

// const data = require('./src/data/test.json')

type testDataType = {
  id: string
  name: string
  data: string[]
}

type TypeData = {
    edges: {
        node: colorDataType
    }
}

type colorDataType = {
    name: string
    tones: {
      default: string,
      light: string,
      dark: string,
      tone: string
    }
  }

export const createPages: GatsbyNode["createPages"] = async ( { graphql, actions } ) => {

  const { createPage } = actions

  const data = await graphql<TypeData>( `
    {
      allSitePage {
        edges {
          node {
            pageContext
          }
        }
      }
    }
  ` 
  )


      
  // Create Post Pages  
  const postTemplate = path.resolve("./src/templates/color.tsx")
  const createPostPromise = data?.allSitePage.edges[0].nodes.map((post) => {
      createPage({
          path : `posts/${post.slug}`,
          component : postTemplate,
          context : {
              slug: post.slug,
              // anything else you want to pass to your context
          }
      })
  })

  await Promise.all( [ createPostPromise] )
}

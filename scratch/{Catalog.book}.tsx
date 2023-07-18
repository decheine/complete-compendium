import React from "react"
import { graphql } from "gatsby"


type SettingDataType = {
  setting_key: string,
  setting_name: string,
  source_books: string[]
}

type BookDataType = {
    publish_id: string,
    title: string,
    monster_keys: string[]
  }

interface BookPageQueryData {
  site: {
    siteMetadata: {
      title: string
    }
  }
  allSitePage: {
    edges: {
      node: {
        pageContext: BookDataType
      }
    }[]
  }
    
}

interface Props {
  readonly data: BookPageQueryData
}

export default function MonsterPage(props: Props) {
    return props.data.allSitePage.edges[0].node.pageContext.publish_id
  }
  
  // This is the page query that connects the data to the actual component. Here you can query for any and all fields
  // you need access to within your code. Again, since Gatsby always queries for `id` in the collection, you can use that
  // to connect to this GraphQL query.
  
export const query = graphql`
query($path: String) {
  allSitePage(filter: { path: { eq: $path } }) {
    edges {
      node {
        pageContext 
      }
    }
  }
}
`
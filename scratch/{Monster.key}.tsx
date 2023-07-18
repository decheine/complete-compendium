import React from "react"
import { graphql } from "gatsby"

interface MonsterPageQueryData {
  site: {
    siteMetadata: {
      title: string
    }
  }
  allSitePage: {
    edges: {
      node: {
        pageContext: colorDataType
      }
    }[]
  }
    
}

interface Props {
  readonly data: PageQueryData
}

export default function MonsterPage(props) {
    return props.data.fields.monster_key
  }
  
  // This is the page query that connects the data to the actual component. Here you can query for any and all fields
  // you need access to within your code. Again, since Gatsby always queries for `id` in the collection, you can use that
  // to connect to this GraphQL query.
  
export const query = graphql`
  query($id: String!) {
    monsters(filter: { id: { eq: $id } }) {
      fields {
        monster_key
      }
    }
  }
`
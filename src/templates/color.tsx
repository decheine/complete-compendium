import React from "react"
import Layout from '../components/Layout';
import {  PageProps, Link, graphql, HeadFC  } from "gatsby";

import { CreatePagesArgs } from 'gatsby';


type colorDataType = {
  name: string
  tones: {
    default: string,
    light: string,
    dark: string,
    tone: string
  }
}

interface PageQueryData {
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

const ColorTemplate: React.FC<Props> = ({data}) => {
  const color = data.allSitePage.edges[0].node.pageContext
  // console.log("color template")
  // console.log(color)

  return (
    <Layout title={color.name}>
      <h2>{color.name}</h2>
    </Layout>
  )
}



export const query = graphql`
  query($path: String!) {
    allSitePage(filter: { path: { eq: $path } }) {
      edges {
        node {
          pageContext 
        }
      }
    }
  }
`

export default ColorTemplate
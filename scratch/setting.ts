import React from "react"
import Layout from '../src/components/Layout';
import {  PageProps, Link, graphql, HeadFC  } from "gatsby";

import { CreatePagesArgs } from 'gatsby';


type settingDataType = {
  setting_key: string
  setting_name: string
  source_books: string[]
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
        pageContext: settingDataType
      }
    }[]
  }
    
}

interface Props {
  readonly data: PageQueryData
}

const SettingTemplate: React.FC<Props> = ({data}) => {
  const setting = data.allSitePage.edges[0].node.pageContext
  console.log("setting template")
  console.log(setting)
  // const {previous, next} = pageContext

  return (
    <Layout title={setting.name}>
      <h2>{setting.name}</h2>
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

export default SettingTemplatee
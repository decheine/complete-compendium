import React from "react"
import Layout from '../src/components/Layout';
import { graphql } from "gatsby";

interface TestPageTemplateProps {
    data: {
      allSitePages: {
        siteMetadata: {
          title: string
          description: string
          author: {
            name: string
            url: string
          }
        }
      }
    }
}

type testDataType = {
  id: string
  name: string
  data: {
    datafield1: string,
    datafield2: string
  }
}

// export default ({ data }) => {
//     var testMember = data.allSitePage.edges[0].node.context;
//     return (
//         <Layout>
//             <h2>{testMember.name</h2>
//         </Layout>
//     )
// }

interface PageQueryData {
  site: {
    siteMetadata: {
      title: string
    }
  }
  testData: {
    id: string
    name: string
    html: string
    frontmatter: {
      title: string
      date: string
    }
  }
}

export const pageQuery = graphql`
  query BlogPostBySlug($slug: String!) {
    site {
      siteMetadata {
        title
      }
    }
    markdownRemark(fields: {slug: {eq: $slug}}) {
      id
      excerpt(pruneLength: 160)
      html
      frontmatter {
        title
        date(formatString: "MMMM DD, YYYY")
      }
    }
  }
`
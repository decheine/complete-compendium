import type { GatsbyConfig } from "gatsby";

const config: GatsbyConfig = {
  siteMetadata: {
    title: `AD&D 2nd Edition Complete Monstrous Compendium`,
    siteUrl: `https://www.completecompendium.com`
  },
  // More easily incorporate content into your pages through automatic TypeScript type generation and better GraphQL IntelliSense.
  // If you use VSCode you can also use the GraphQL plugin
  // Learn more at: https://gatsby.dev/graphql-typegen
  graphqlTypegen: true,
  plugins: [
    "gatsby-plugin-image", "gatsby-plugin-sitemap", {
    resolve: 'gatsby-plugin-manifest',
    options: {
      icon: "src/images/icon.png",
      name: `Advanced Dungeons and Dragons Complete Monster Compendium`,
      short_name: `AD&D Complete Compendium`,
      start_url: `/`,
      background_color: `#FFFFFF`,
      theme_color: `#1250A2`,
      display: `standalone`,
    }
  }, "gatsby-plugin-mdx", "gatsby-plugin-sharp", "gatsby-transformer-sharp", {
    resolve: 'gatsby-source-filesystem',
    options: {
      "name": "images",
      "path": "./src/images/"
    },
    __key: "images"
  }, {
    resolve: 'gatsby-source-filesystem',
    options: {
      "name": "pages",
      "path": "./src/pages/"
    },
    __key: "pages"
  },
  {
    resolve: `gatsby-plugin-alias-imports`,
    options: {
      alias: {
        "@src": "src",
        "@components": "src/components",
        "@layouts": "src/layouts",
        "@pages": "src/pages",
        "@fonts": "src/fonts",
        "@images": "src/images",
        "@data": "src/data",
        "@templates": "src/templates",
        "@types": "src/types",
        "@styles": "src/styles",
      },
      extensions: [
        "js",
      ],
    }
  }
]
};

export default config;

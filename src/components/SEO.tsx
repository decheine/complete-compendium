import React, { PropsWithChildren } from "react"

type SEOprops = {

}

export const SEO = (props: PropsWithChildren<SEOprops>) => {

  return (
    <>
          <meta property="og:title" content="AD&D 2nd Edition Complete Monstrous Compendium"/>
          <meta property="og:description" content="Complete browsable, searchable appendix of EVERY monster, sourcebook, manual, and campaign setting in Advanced Dungeons & Dragons 2nd Edition."/>
          <meta property="og:url" content="https://completecompendium.com"/>
          <meta property="og:image" content="https://completecompendium.com/opengraph_banner.webp"/>
          <meta property="og:image:width" content="1200"/>
          <meta property="og:image:height" content="630"/>

          <meta property="og:type" content="website"/>
          <meta name="twitter:card" content="summary_large_image"/>
          <meta name="twitter:image" content="https://completecompendium.com/opengraph_banner.webp"/>

          <meta name="twitter:site" content="@completecompendium" />
          <meta name="twitter:title" content="Advanced Dungeons & Dragons 2nd Edition Complete Compendium" />
          <meta name="twitter:description" content="Complete browsable, searchable appendix of EVERY monster, sourcebook, manual, and campaign setting in Advanced Dungeons & Dragons 2nd Edition" />
        {props.children}
    </>
  )
}
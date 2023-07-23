import React from 'react';
import { Helmet } from 'react-helmet';

interface HeadProps {
    title: string,
    description: string
}

const Head = ({ title, description }: HeadProps) => {
  return (
    <>
      <Helmet
        defaultTitle="Monster Title - Complete Compendium"
        title={title}
        titleTemplate="%s - Complete Compendium"
      />
    </>
  )
}

export default Head;
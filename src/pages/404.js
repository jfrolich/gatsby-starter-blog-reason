// you can easily have js files coexist with reason files, like this page!
import React from "react"
import { graphql } from "gatsby"

import { make as Layout } from "../components/Layout.bs"
import { make as SEO } from "../components/SEO.bs"

const NotFoundPage = ({ data, location }) => {
  const siteTitle = data.site.siteMetadata.title

  return (
    <Layout location={location} title={siteTitle}>
      <SEO title="404: Not Found" />
      <h1>Not Found</h1>
      <p>You just hit a route that doesn&#39;t exist... the sadness.</p>
    </Layout>
  )
}

export default NotFoundPage

export const pageQuery = graphql`
  query {
    site {
      siteMetadata {
        title
      }
    }
  }
`

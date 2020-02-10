[%graphql
  {|
    fragment NextPrevious on MarkdownRemark {
      fields {
        slug
      }
      frontmatter {
        title
      }
    }
|};
  {taggedTemplate: false, inline: true}
];

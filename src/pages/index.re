open Typography;

[%graphql
  {|
  query {
    site {
      siteMetadata {
        title
      }
    }
    allMarkdownRemark(sort: { fields: [frontmatter___date], order: DESC }) {
      edges {
        node {
          excerpt
          fields {
            slug
          }
          frontmatter {
            date(formatString: "MMMM DD, YYYY")
            title
            description
          }
        }
      }
    }
  }
|};
  {inine: true}
];

[@react.component]
let make = (~data, ~location: Gatsby.location) => {
  switch (parse(data)) {
  | {
      site: Some({siteMetadata: Some({title: Some(title)})}),
      allMarkdownRemark: {edges},
    } =>
    <Layout location title>
      {Belt.Array.map(
         edges,
         fun
         | {
             node: {
               fields: Some({slug: Some(slug)}),
               excerpt,
               frontmatter: Some({title, date, description}),
             },
           } =>
           <article key=slug>
             <header>
               <h3
                 style={ReactDOMRe.Style.make(
                   ~marginBottom=rhythm(0.25),
                   (),
                 )}>
                 <Gatsby.Link
                   style={ReactDOMRe.Style.make(~boxShadow="none", ())}
                   _to=slug>
                   {Belt.Option.getWithDefault(title, slug)->React.string}
                 </Gatsby.Link>
               </h3>
               <small>
                 {date
                  ->Belt.Option.flatMap(s => s->Js.Json.decodeString)
                  ->Belt.Option.getWithDefault("")
                  ->React.string}
               </small>
             </header>
             <section>
               <p
                 dangerouslySetInnerHTML={
                   "__html":
                     Belt.Option.getWithDefault(
                       description,
                       Belt.Option.getWithDefault(excerpt, ""),
                     ),
                 }
               />
             </section>
           </article>

         | _ => React.null,
       )
       ->React.array}
    </Layout>

  | _ => React.null
  };
};

// export the component as default
let default = make;

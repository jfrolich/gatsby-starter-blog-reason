open Typography;

[%graphql
  {|
  query BlogPostBySlug($slug: String!) {
    site {
      siteMetadata {
        title
      }
    }
    markdownRemark(fields: { slug: { eq: $slug } }) {
      id
      excerpt(pruneLength: 160)
      html
      frontmatter {
        title
        date(formatString: "MMMM DD, YYYY")
        description
      }
    }
  }
|};
  {inline: true}
];

type pageContext = {
  previous: option(NextPreviousFragment.t),
  next: option(NextPreviousFragment.t),
};

[@react.component]
let make = (~data, ~pageContext: pageContext, ~location: Gatsby.location) => {
  let data = parse(data);

  switch (data) {
  | {
      markdownRemark:
        Some({
          frontmatter: Some({title: Some(title), description, date}),
          excerpt,
          html: Some(html),
        }),
      site: Some({siteMetadata: Some({title: Some(siteTitle)})}),
    } =>
    <Layout location title=siteTitle>
      <SEO
        title
        description={Belt.Option.getWithDefault(
          description,
          Belt.Option.getWithDefault(excerpt, ""),
        )}
      />
      <article>
        <header>
          <h1
            style={ReactDOMRe.Style.make(
              ~marginTop=rhythm(1.),
              ~marginBottom="0px",
              (),
            )}>
            title->React.string
          </h1>
          <p
            style=ReactDOMRe.Style.(
              combine(
                scale((-1.) /. 5.),
                make(~display="block", ~marginBottom=rhythm(1.), ()),
              )
            )>
            {date
             ->Belt.Option.flatMap(d => d->Js.Json.decodeString)
             ->Belt.Option.getWithDefault("")
             ->React.string}
          </p>
        </header>
        <section dangerouslySetInnerHTML={"__html": html} />
        <hr style={ReactDOMRe.Style.make(~marginBottom=rhythm(1.), ())} />
        <footer> <Bio /> </footer>
      </article>
      <nav>
        <ul
          style={ReactDOMRe.Style.make(
            ~display="flex",
            ~flexWrap="wrap",
            ~justifyContent="space-between",
            ~listStyle="none",
            ~padding="0px",
            (),
          )}>
          <li>
            {switch (pageContext.previous) {
             | Some({
                 fields: Some({slug: Some(slug)}),
                 frontmatter: Some({title: Some(title)}),
               }) =>
               <Gatsby.Link _to=slug>
                 {j|← $title |j}->React.string
               </Gatsby.Link>
             | _ => React.null
             }}
          </li>
          <li>
            {switch (pageContext.next) {
             | Some({
                 fields: Some({slug: Some(slug)}),
                 frontmatter: Some({title: Some(title)}),
               }) =>
               <Gatsby.Link _to=slug>
                 {j|$title →|j}->React.string
               </Gatsby.Link>
             | _ => React.null
             }}
          </li>
        </ul>
      </nav>
    </Layout>
  | _ => React.null
  };
};

let default = make;

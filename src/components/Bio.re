open GatsbyImage.Fragments;
open Typography;

[%graphql
  {|
    query BioQuery {
      avatar: file(absolutePath: { regex: "/profile-pic.jpg/" }) {
        childImageSharp {
          fixed(width: 50, height: 50) {
            ...GatsbyImageSharpFixed
          }
        }
      }
      site {
        siteMetadata {
          author {
            name
            summary
          }
          social {
            twitter
          }
        }
      }
    }
|};
  {inline: true}
];

[@react.component]
let make = () => {
  let data = parse(Gatsby.useStaticQuery(query));
  let fixedImage =
    switch (data.avatar) {
    | Some({childImageSharp: Some({fixed: Some(fixedImage)})}) =>
      Some([|GatsbyImage.gatsbyImageSharpFixed(fixedImage)|])
    | _ => None
    };

  let author =
    switch (data.site) {
    | Some({siteMetadata: Some({author})}) => author
    | _ => None
    };

  let twitter =
    switch (data.site) {
    | Some({siteMetadata: Some({social: Some({twitter})})}) => twitter
    | _ => None
    };

  <div
    style={ReactDOMRe.Style.make(
      ~display="flex",
      ~marginBottom=rhythm(2.5),
      (),
    )}>
    {switch (fixedImage) {
     | Some(fixed) =>
       <GatsbyImage
         fixed
         alt=?(author->Belt.Option.flatMap(a => a.name))
         style={ReactDOMRe.Style.make(
           ~marginRight=rhythm(0.5),
           ~marginBottom="0px",
           ~minWidth="50px",
           ~borderRadius="100%",
           (),
         )}
       />
     | None => React.null
     }}
    {switch (author, twitter) {
     | (Some({name: Some(name), summary}), Some(twitter)) =>
       <p>
         "Written by "->React.string
         <strong> name->React.string </strong>
         {summary->Belt.Option.map(s => " " ++ s)->Belt.Option.getWithDefault("")->React.string}
         <a href={"https://twitter.com/" ++ twitter}>
           "You should follow him on Twitter"->React.string
         </a>
       </p>
     | _ => React.null
     }}
  </div>;
};

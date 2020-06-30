[%graphql
  {|
    query SEO {
      site {
        siteMetadata {
          title
          description
          author {
            name
          }
        }
      }
    }
  |};
  {inline: true}
];

[@react.component]
let make = (~description=?, ~lang="en", ~meta as passedMeta=[||], ~title) => {
  // We need to parse the query to get ReasonML runtime types.
  let site = Gatsby.useStaticQuery(query)->unsafe_fromJson->parse.site;

  let metaTitle =
    switch (site) {
    | Some({siteMetadata: Some({title})}) => title
    | _ => None
    };

  let author =
    switch (site) {
    | Some({siteMetadata: Some({author: Some({name})})}) => name
    | _ => None
    };

  let metaDescription =
    switch (description, site) {
    | (Some(description), _) => Some(description)
    | (_, Some({siteMetadata: Some({description: Some(description)})})) =>
      Some(description)
    | _ => None
    };

  <Helmet
    title
    htmlAttributes={lang: lang}
    titleTemplate={
      metaTitle
      ->Belt.Option.map(metaTitle => "%s | " ++ metaTitle)
      ->Belt.Option.getWithDefault("%s")
    }
    meta=Helmet.(
      [|
        Belt.Option.map(metaDescription, description =>
          meta(~property="description", ~content=description, ())
        ),
        Some(meta(~property="og:title", ~content=title, ())),
        Belt.Option.map(description, description =>
          meta(~property="og:description", ~content=description, ())
        ),
        Some(meta(~property="og:type", ~content="website", ())),
        Some(meta(~name="twitter:card", ~content="summary", ())),
        Belt.Option.map(author, author =>
          meta(~name="twitter:creator", ~content=author, ())
        ),
        Some(meta(~name="twitter:title", ~content=title, ())),
        Belt.Option.map(description, description =>
          meta(~name="twitter:description", ~content=description, ())
        ),
      |]
      ->Belt.Array.keepMap(a => a)
      |> Js.Array.concat(passedMeta)
    )
  />;
};

let default = make;

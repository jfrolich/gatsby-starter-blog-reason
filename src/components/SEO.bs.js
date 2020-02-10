// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Gatsby from "gatsby";
import * as Belt_Array from "bs-platform/lib/es6/belt_Array.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as ReactHelmet from "react-helmet";

var query = (graphql`
  query SEO  {
    site  {
      siteMetadata  {
        title
        description
        author
      }
    }
  }
`);

function parse(value) {
  var value$1 = value["site"];
  var tmp;
  if (value$1 == null) {
    tmp = undefined;
  } else {
    var value$2 = value$1["siteMetadata"];
    var tmp$1;
    if (value$2 == null) {
      tmp$1 = undefined;
    } else {
      var value$3 = value$2["title"];
      var value$4 = value$2["description"];
      var value$5 = value$2["author"];
      tmp$1 = {
        title: (value$3 == null) ? undefined : value$3,
        description: (value$4 == null) ? undefined : value$4,
        author: (value$5 == null) ? undefined : value$5
      };
    }
    tmp = {
      siteMetadata: tmp$1
    };
  }
  return {
          site: tmp
        };
}

function makeVar(f, param) {
  return Curry._1(f, null);
}

var definition = /* tuple */[
  parse,
  query,
  makeVar
];

function SEO(Props) {
  var description = Props.description;
  var $staropt$star = Props.lang;
  var $staropt$star$1 = Props.meta;
  var title = Props.title;
  var lang = $staropt$star !== undefined ? $staropt$star : "en";
  var passedMeta = $staropt$star$1 !== undefined ? $staropt$star$1 : [];
  var site = parse(Gatsby.useStaticQuery(query)).site;
  var metaTitle;
  if (site !== undefined) {
    var match = site.siteMetadata;
    metaTitle = match !== undefined ? match.title : undefined;
  } else {
    metaTitle = undefined;
  }
  var author;
  if (site !== undefined) {
    var match$1 = site.siteMetadata;
    author = match$1 !== undefined ? match$1.author : undefined;
  } else {
    author = undefined;
  }
  var metaDescription;
  if (description !== undefined) {
    metaDescription = description;
  } else if (site !== undefined) {
    var match$2 = site.siteMetadata;
    if (match$2 !== undefined) {
      var match$3 = match$2.description;
      metaDescription = match$3 !== undefined ? match$3 : undefined;
    } else {
      metaDescription = undefined;
    }
  } else {
    metaDescription = undefined;
  }
  return React.createElement(ReactHelmet.Helmet, {
              htmlAttributes: {
                lang: lang
              },
              titleTemplate: Belt_Option.getWithDefault(Belt_Option.map(metaTitle, (function (metaTitle) {
                          return "%s | " + metaTitle;
                        })), "%s"),
              title: title,
              meta: Belt_Array.keepMap([
                      Belt_Option.map(metaDescription, (function (description) {
                              return {
                                      property: "description",
                                      content: description
                                    };
                            })),
                      {
                        property: "og:title",
                        content: title
                      },
                      Belt_Option.map(description, (function (description) {
                              return {
                                      property: "og:description",
                                      content: description
                                    };
                            })),
                      {
                        property: "og:type",
                        content: "website"
                      },
                      {
                        name: "twitter:card",
                        content: "summary"
                      },
                      Belt_Option.map(author, (function (author) {
                              return {
                                      name: "twitter:creator",
                                      content: author
                                    };
                            })),
                      {
                        name: "twitter:title",
                        content: title
                      },
                      Belt_Option.map(description, (function (description) {
                              return {
                                      name: "twitter:description",
                                      content: description
                                    };
                            }))
                    ], (function (a) {
                        return a;
                      })).concat(passedMeta)
            });
}

var make = SEO;

var $$default = SEO;

export {
  query ,
  parse ,
  makeVar ,
  definition ,
  make ,
  $$default ,
  $$default as default,
  
}
/* query Not a pure module */

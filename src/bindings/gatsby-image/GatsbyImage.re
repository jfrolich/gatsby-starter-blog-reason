module Fragments = {
  [%graphql
    {|
    fragment GatsbyImageSharpFixed on ImageSharpFixed {
      base64
      width
      height
      src
      srcSet
    }
  |}
  ];
};

type fixed;
// This allows polymorphism in the fixed argument, so it can accept more than
// one type of fragment.
// It is safe because we have multiple function that only convert valid fragment
// types to the opaque "fixed" type.
external gatsbyImageSharpFixed: Fragments.GatsbyImageSharpFixed.t => fixed =
  "%identity";

[@bs.module "gatsby-image"] [@react.component]
external make:
  (
    ~fixed: array(fixed)=?,
    ~fadeIn: bool=?,
    ~durationFadeIn: int=?,
    ~title: string=?,
    ~alt: string=?,
    ~crossOrigin: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~imgStyle: ReactDOMRe.Style.t=?,
    ~placeholderStyle: ReactDOMRe.Style.t=?,
    ~placeholderClassName: string=?,
    ~backgroundColor: string=?
  ) =>
  React.element =
  "default";

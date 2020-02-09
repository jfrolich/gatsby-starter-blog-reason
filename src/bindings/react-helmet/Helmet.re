type htmlAttributes = {lang: string};
type bodyAttributes;
type titleAttributes;
[@bs.deriving abstract]
type meta = {
  [@bs.optional]
  name: string,
  [@bs.optional]
  property: string,
  [@bs.optional]
  content: string,
};
type base;
type link;
type style;
type script;
type noscript;

[@bs.module "react-helmet"] [@react.component]
external make:
  (
    ~defer: bool=?,
    ~encodeSpecialCharacters: bool=?,
    ~onChangeClientState: unit => unit=?,
    ~htmlAttributes: htmlAttributes=?,
    ~bodyAttributes: bodyAttributes=?,
    ~titleAttributes: titleAttributes=?,
    ~defaultTitle: string=?,
    ~titleTemplate: string=?,
    // some <head> tags can be passed as props
    ~base: base=?,
    ~title: string=?,
    ~meta: array(meta)=?,
    ~link: array(link)=?,
    ~style: array(style)=?,
    ~script: array(script)=?,
    ~noscript: array(noscript)=?,
    ~children: React.element=?
  ) =>
  React.element =
  "Helmet";

type helmetProp = {
  .
  [@bs.meth] "toComponent": unit => React.element,
  [@bs.meth] "toString": unit => string,
};
type helmet = {
  .
  "base": helmetProp,
  "bodyAttributes": helmetProp,
  "htmlAttributes": helmetProp,
  "link": helmetProp,
  "meta": helmetProp,
  "noscript": helmetProp,
  "script": helmetProp,
  "style": helmetProp,
  "title": helmetProp,
};
[@bs.val] [@bs.module "react-helmet"] [@bs.scope "Helmet"]
external renderStatic: unit => helmet = "renderStatic";

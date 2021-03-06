// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE


var query = (graphql`
  fragment GatsbyImageSharpFixed on ImageSharpFixed   {
    base64
    width
    height
    src
    srcSet
  }
`);

var Raw = {};

function parse(value) {
  var value$1 = value.base64;
  return {
          base64: !(value$1 == null) ? value$1 : undefined,
          width: value.width,
          height: value.height,
          src: value.src,
          srcSet: value.srcSet
        };
}

var verifyArgsAndParse = parse;

function serialize(value) {
  var value$1 = value.srcSet;
  var value$2 = value.src;
  var value$3 = value.height;
  var value$4 = value.width;
  var value$5 = value.base64;
  var base64 = value$5 !== undefined ? value$5 : null;
  return {
          base64: base64,
          width: value$4,
          height: value$3,
          src: value$2,
          srcSet: value$1
        };
}

function verifyName(param) {
  
}

var Z__INTERNAL = {
  graphql: 0,
  graphql_module: 0
};

var GatsbyImageSharpFixed = {
  query: query,
  Raw: Raw,
  parse: parse,
  verifyArgsAndParse: verifyArgsAndParse,
  serialize: serialize,
  verifyName: verifyName,
  Z__INTERNAL: Z__INTERNAL
};

var Fragments = {
  GatsbyImageSharpFixed: GatsbyImageSharpFixed
};

export {
  Fragments ,
  
}
/* query Not a pure module */

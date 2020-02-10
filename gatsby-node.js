// this is required for allowing es6 imports in the gatsby-node file
require = require("esm")(module)
module.exports = require("./gatsby-node.esm.js")

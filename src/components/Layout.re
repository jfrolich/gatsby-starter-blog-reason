open Typography;

[@react.component]
let make = (~location: Gatsby.location, ~title, ~children) => {
  <div
    style={ReactDOMRe.Style.make(
      ~marginLeft="auto",
      ~marginRight="auto",
      ~maxWidth=rhythm(24.),
      ~padding=rhythm(1.5) ++ " " ++ rhythm(3. /. 4.),
      (),
    )}>
    <header>
      {switch (location) {
       | {pathname: "/"} =>
         <h1
           style=ReactDOMRe.Style.(
             combine(
               scale(1.5),
               make(~marginBottom=rhythm(1.5), ~marginTop="0px", ()),
             )
           )>
           <Gatsby.Link
             _to="/"
             style={ReactDOMRe.Style.make(
               ~boxShadow="none",
               ~textDecoration="none",
               ~color="inherit",
               (),
             )}>
             title->React.string
           </Gatsby.Link>
         </h1>
       | _ =>
         <h3
           style={ReactDOMRe.Style.make(
             ~fontFamily="Montserrat, sans-serif",
             ~marginTop="0px",
             (),
           )}>
           <Gatsby.Link
             style={ReactDOMRe.Style.make(
               ~boxShadow="none",
               ~textDecoration="none",
               ~color="inherit",
               (),
             )}
             _to="/">
             title->React.string
           </Gatsby.Link>
         </h3>
       }}
    </header>
    <main> children </main>
    <footer>
      {(
         {js|© |js}
         ++ Js.Date.make()->Js.Date.getFullYear->Js.Float.toString
         ++ " Built with "
       )
       ->React.string}
      <a href="https://www.gatsbyjs.org"> "Gatsby"->React.string </a>
    </footer>
  </div>;
};

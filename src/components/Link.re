[@react.component]
let make = (~href: string, ~text: string) =>
  <mark> <a href> {ReasonReact.string(text)} </a> </mark>;

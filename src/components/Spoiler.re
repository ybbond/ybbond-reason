module Styles = {
  open Css;

  let summary =
    style([
      fontSize(`em(1.0)),
      marginTop(`em(1.0)),
      marginBottom(`em(1.0)),
      marginLeft(`px(0)),
      marginRight(`px(0)),
      flex(`num(1.0)),
      textAlign(`left),
      outlineStyle(`none),
      cursor(`pointer),
      userSelect(`none),
    ]);
};

type state = {isopen: bool};

let initialState = {isopen: false};

type action =
  | Toggle;

[@react.component]
let make = (~content: ReasonReact.reactElement, ~title: string) =>
  <details>
    <summary className=Styles.summary> {ReasonReact.string(title)} </summary>
    content
  </details>;

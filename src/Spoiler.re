module Styles = {
  open Css;

  let summary =
    style([
      marginTop(em(1.0)),
      marginBottom(em(1.0)),
      marginLeft(px(0)),
      marginRight(px(0)),
      flex(`num(1.0)),
      textAlign(`left),
      /* outline(`none), */
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
  <summary className=Styles.summary>
    <details> {ReasonReact.string(title)} </details>
    content
  </summary>;

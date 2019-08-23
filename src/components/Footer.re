module Styles = {
  open Css;

  let footer =
    style([
      width(`percent(100.0)),
      paddingTop(`px(30)),
      marginTop(`px(0)),
      marginLeft(`auto),
      marginRight(`auto),
      marginBottom(`em(1.0)),
      maxWidth(`em(50.0)),
    ]);
};

[@react.component]
let make = () =>
  <footer className=Styles.footer>
    <p> {ReasonReact.string("See you sooner :)")} </p>
    <p>
      {ReasonReact.string("@19/08/2019  ")}
      <Link text="ybbond" href="https://github.com/ybbond/ybbond-reason" />
    </p>
  </footer>;

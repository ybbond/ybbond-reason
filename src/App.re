module Styles = {
  open Css;

  let container =
    style([
      minHeight(vh(100.0)),
      flexGrow(1.0),
      flexShrink(1.0),
      flexBasis(`auto),
      display(`flex),
      flexDirection(`column),
      textAlign(`left),
      padding(em(1.0)),
      paddingTop(px(0)),
      paddingBottom(px(0)),
      fontSize(em(0.9)),
    ]);

  let main =
    style([
      flexGrow(1.0),
      width(`percent(100.0)),
      marginTop(px(0)),
      marginBottom(px(0)),
      marginLeft(`auto),
      marginRight(`auto),
      maxWidth(em(50.0)),
    ]);
};

[@react.component]
let make = () => {
  let url = ReasonReact.Router.useUrl();

  let content = () =>
    switch (url.path) {
    | ["/uses"] => <CurViScene />
    | _ => <CurViScene />
    };

  <div className=Styles.container>
    <main className=Styles.main>
      <Styled dark=true />
      {content()}
    </main>
  </div>;
};

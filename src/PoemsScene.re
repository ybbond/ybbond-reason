module Styles = {
  open Css;
  let pre =
    style([
      paddingLeft(`em(1.4)),
      fontFamily("Cousine for Powerline, monospace"),
      display(`block),
      whiteSpace(`preWrap),
      maxWidth(`px(544)),
      fontSize(`em(0.9)),
      lineHeight(`em(2.8)),
      media(
        "(max-width: 414px)",
        [fontSize(`em(0.8)), lineHeight(`em(3.0))],
      ),
    ]);
};

[@react.component]
let make = () => {
  open PoemContent;
  let content: array(poemContent) = content;
  let contentMapped =
    Array.mapi(
      (key, item) => {
        let contentPre =
          <pre className=Styles.pre> {ReasonReact.string(item.script)} </pre>;
        <Spoiler
          title={item.title}
          content=contentPre
          key={string_of_int(key)}
        />;
      },
      content,
    );

  <React.Fragment> {ReasonReact.array(contentMapped)} </React.Fragment>;
};

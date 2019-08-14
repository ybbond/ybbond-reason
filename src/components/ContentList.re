module Styles = {
  open Css;
  let ul =
    style([
      marginLeft(em(2.5)),
      marginTop(em(0.8)),
      paddingLeft(px(0)),
      listStyle(`none, `inside, `none),
    ]);

  let pDefault =
    style([
      before([
        position(`absolute),
        marginLeft(em(-1.5)),
        contentRule({j|•|j}),
      ]),
    ]);

  let pDone =
    style([
      before([
        position(`absolute),
        marginLeft(em(-1.5)),
        contentRule({j|⊗|j}),
      ]),
    ]);

  let pProgress =
    style([
      before([
        position(`absolute),
        marginLeft(em(-1.5)),
        contentRule({j|⊙|j}),
      ]),
    ]);
};

type listType =
  | Default
  | Progress
  | Done;
type listContent = {
  text: ReasonReact.reactElement,
  variant: listType,
};

[@react.component]
let make = (~content: array(listContent)) => {
  let contentMapped =
    Array.map(
      (item: listContent) => {
        let listPointType =
          switch (item.variant) {
          | Progress => Styles.pProgress
          | Done => Styles.pDone
          | Default => Styles.pDefault
          };
        <li> <p className=listPointType> {item.text} </p> </li>;
      },
      content,
    );

  <ul className=Styles.ul> {ReasonReact.array(contentMapped)} </ul>;
};

module Styles = {
  open Css;
  let ul = style([
    marginLeft(em(2.5)),
    marginTop(em(0.8)),
    paddingLeft(px(0)),
    /* listStyle((`outside, `none)), */
  ]);
}

type listContent = {
  text: ReasonReact.reactElement,
  customClass: string,
};

[@react.component]
let make = (~content: list(listContent)) => {
  let contentMapped = List.map((item, key) => {
    <li key={key}>
      <p></p>
    </li>
  }, content);
  <ul className=Styles.ul>
    <li><span>{ReasonReact.string("Hell")}</span></li>
  </ul>
};

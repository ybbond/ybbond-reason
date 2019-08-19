module Styles = {
  open Css;

  let strikethrough = style([textDecoration(`lineThrough)]);
  let underline = style([textDecoration(`underline)]);
  let h1 = style([fontWeight(`num(400)), fontSize(`em(1.4))]);
};

type contentType = {
  title: string,
  path: string,
};

let content: array(contentType) = [|
  {title: "CV", path: "/"},
  {title: "Poems-Verses", path: "poems"},
  {title: "Uses", path: "uses"},
|];

[@react.component]
let make = (~current: string) => {
  let contentElements =
    Array.mapi(
      (index, item) => {
        let separator = index !== Array.length(content) - 1 ? " / " : "";
        let res =
          item.path === current
            ? <React.Fragment key=index>
                <span className=Styles.strikethrough>
                  {ReasonReact.string(item.title)}
                </span>
                <span> {ReasonReact.string(separator)} </span>
              </React.Fragment>
            : <React.Fragment key=index>
                <Link internal={item.path} text={item.title} />
                <span> {ReasonReact.string(separator)} </span>
              </React.Fragment>;

        res;
      },
      content,
    );

  <React.Fragment>
    <h1 className=Styles.h1>
      {ReasonReact.string("Yohanes Bandung Bondowoso")}
    </h1>
    {React.array(contentElements)}
  </React.Fragment>;
};

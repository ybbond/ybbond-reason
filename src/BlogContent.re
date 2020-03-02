module Styles = {
  open Css;
  let h1 = style([fontWeight(`num(600)), fontSize(`em(1.2))]);
  let summary =
    style([
      fontSize(`em(1.0)),
      marginTop(`em(1.0)),
      marginBottom(`em(1.0)),
      marginLeft(`px(0)),
      marginRight(`px(0)),
      flex(`num(1.0)),
      textAlign(`left),
      cursor(`pointer),
      userSelect(`none),
    ]);
};

type state = {blog_content: string};

type action =
  | Loaded(string);

[@react.component]
let make =
    (~link: string, ~source: string, ~title: string, ~createdAt: string) => {
  let (state, dispatch) =
    React.useReducer(
      (_state, action) =>
        switch (action) {
        | Loaded(data) => {blog_content: data}
        },
      {blog_content: "Mengambil data konten blog..."},
    );

  React.useEffect0(() => {
    BlogGistData.fetchBlog(data => dispatch(Loaded(data)), link) |> ignore;
    None;
  });

  <details>
    <summary className=Styles.summary> {ReasonReact.string(title)} </summary>
    <h1 className=Styles.h1>
      {ReasonReact.string("# " ++ title ++ " [")}
      <Link href=source text="link" />
      {ReasonReact.string("]")}
    </h1>
    <date>
      {ReasonReact.string(createdAt |> Js.Date.fromString |> Js.Date.toString)}
    </date>
    <pre> {ReasonReact.string(state.blog_content)} </pre>
  </details>;
};

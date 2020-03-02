module Styles = {
  open Css;
  let h1 =
    style([
      fontWeight(`num(600)),
      fontSize(`em(1.2)),
      media("(max-width: 544px)", [fontSize(`em(1.1))]),
    ]);

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

  let date =
    style([
      fontFamily("Cousine for Powerline, monospace"),
      fontSize(`em(0.8)),
      color(`hex("777777")),
      whiteSpace(`nowrap),
    ]);

  let pre =
    style([
      fontFamily("Cousine for Powerline, monospace"),
      display(`block),
      whiteSpace(`preWrap),
      maxWidth(`px(544)),
      fontSize(`em(0.9)),
      lineHeight(`em(2.8)),
      media(
        "(max-width: 544px)",
        [fontSize(`em(0.8)), lineHeight(`em(3.0))],
      ),
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
    <h1 className=Styles.h1> {ReasonReact.string("# " ++ title)} </h1>
    <span className=Styles.date>
      <time>
        {ReasonReact.string(
           createdAt |> Js.Date.fromString |> Js.Date.toLocaleString,
         )}
      </time>
      {ReasonReact.string(" [")}
      <Link href=source text="link" />
      {ReasonReact.string("]")}
    </span>
    <pre className=Styles.pre> {ReasonReact.string(state.blog_content)} </pre>
  </details>;
};

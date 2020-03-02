type state = {blog_content: string};

type action =
  | Loaded(string);

[@react.component]
let make = (~link: string) => {
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

  <pre> {ReasonReact.string(state.blog_content)} </pre>;
};

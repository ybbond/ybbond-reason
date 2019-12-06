type state = {gist_content: option(BlogGistData.gist_return)};

type action =
  | Loaded(BlogGistData.gist_return);

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (_state, action) =>
        switch (action) {
        | Loaded(data) => {gist_content: Some(data)}
        },
      {gist_content: None},
    );

  React.useEffect0(() => {
    BlogGistData.fetchGist(data => dispatch(Loaded(data))) |> ignore;
    None;
  });

  <React.Fragment>
    <h3> {ReasonReact.string("Blog")} </h3>
    {switch (state.gist_content) {
     | Some(story) =>
       Js.log(story);
       <div> {React.string("hello")} </div>;
     | None => React.string("loading")
     }}
  </React.Fragment>;
};

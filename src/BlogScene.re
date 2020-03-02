open BlogGistData;

module Styles = {
  open Css;

  let strikethrough = style([textDecoration(`lineThrough)]);
  let underline = style([textDecoration(`underline)]);
  let h1 = style([fontWeight(`num(600)), fontSize(`em(1.4))]);
};

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
    {switch (state.gist_content) {
     | Some(story) =>
       let comp =
         Array.mapi(
           (key, item: gist_type) => {
             let blogContent = Js.Dict.get(item.files, "_blog.md");

             switch (blogContent) {
             | Some(value) =>
               <div key={string_of_int(key)}>
                 <BlogContent
                   source={item.html_url}
                   link={value.raw_url}
                   title={item.description}
                   createdAt={item.created_at}
                 />
               </div>
             | None => <div />
             };
           },
           story,
         );
       <div> {ReasonReact.array(comp)} </div>;
     | None => React.string("Mengambil data blog...")
     }}
  </React.Fragment>;
};

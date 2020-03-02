open BlogGistData;

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
       let comp =
         Array.mapi(
           (key, item: gist_type) => {
             let blogContent = Js.Dict.get(item.files, "_blog.md");

             switch (blogContent) {
             | Some(value) =>
               <div key={string_of_int(key)}>
                 <h1> {ReasonReact.string("# " ++ item.description)} </h1>
                 <date> {ReasonReact.string(item.created_at)} </date>
                 <BlogContent link={value.raw_url} />
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

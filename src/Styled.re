open Utils;

type state = {dark: bool};
type action =
  | ToggleDark;

let initialState = {dark: false};

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | ToggleDark => {dark: !state.dark}
        },
      initialState,
    );
  let backgroundColor = state.dark ? "#1b1b1b" : "#fdfdfd";
  let textColor = state.dark ? "#fdfdfd" : "#1b1b1b";
  let markColor = state.dark ? "#3e3e3e" : "#d8dcd5";
  let markHover = state.dark ? "#d8dcd6" : "#2d2d2d";
  let anchorColor = state.dark ? "#d8dcd5" : "#2d2d2d";
  let anchorHover = state.dark ? "#2d2d2d" : "#d8dcd5";

  let htmlStyle =
    "html { height: 100vh; font-family: 'Cousine', monospace; background-color:"
    ++ backgroundColor
    ++ "; color:"
    ++ textColor
    ++ "; }";
  let fontFace = "@import url('https://fonts.googleapis.com/css?family=Cousine:400,700&display=swap');";
  let bodyStyle = {j|
body {
  display: flex;
  min-height: 100vh;
  flex-direction: column;
  margin: 0;
  padding: 0;
  line-height: 1.8em;
  letter-spacing: -0.01em;
  word-wrap: break-word;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
}
  |j};
  let miscStyle = {j|
::selection {
  background-color: #79d688;
}
  |j};
  let markStyle =
    "mark{background-color:"
    ++ markColor
    ++ ";}"
    ++ "mark:hover{background-color:"
    ++ markHover
    ++ ";}";
  let anchorStyle =
    "a{text-decoration: none;cursor: pointer;color:"
    ++ anchorColor
    ++ ";}"
    ++ "a:hover{color:"
    ++ anchorHover
    ++ ";}";

  let setStyle =
    htmlStyle ++ fontFace ++ bodyStyle ++ miscStyle ++ markStyle ++ anchorStyle;

  <React.Fragment>
    <style dangerouslySetInnerHTML={dangerousHtml(setStyle)} />
    <button onClick={_ => dispatch(ToggleDark)}>
      {ReasonReact.string("hai")}
    </button>
  </React.Fragment>;
};

open Utils;

module Styles = {
  open Css;
  let toggler =
    style([cursor(`pointer), userSelect(`none), marginTop(`em(2.0))]);
};

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

  let htmlStyle = {j|
html {
  height: 100vh;
  background-color: $backgroundColor;
  color: $textColor;
}
|j};

  let fontFace = {j|
@font-face {
  font-family: 'Cousine for Powerline';
  font-style: normal;
  font-weight: 400;
  src: url('../assets/fonts/Cousine for Powerline.ttf'); /* IE9 Compat Modes */
}
  |j};

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
  font-family: 'Cousine for Powerline', monospace;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
}
  |j};

  let miscStyle = {j|
::selection {
  background-color: #79d688;
}
  |j};

  let markStyle = {j|
mark {
  background-color: $markColor;
}
mark:hover {
  background-color: $markHover;
}
|j};

  let anchorStyle = {j|
a {
  text-decoration: none;
  cursor: pointer;
  color: $anchorColor;
}
a:hover {
  color: $anchorHover;
}
|j};

  let setStyle =
    htmlStyle ++ fontFace ++ bodyStyle ++ miscStyle ++ markStyle ++ anchorStyle;

  <React.Fragment>
    <style dangerouslySetInnerHTML={dangerousHtml(setStyle)} />
    <div onClick={_ => dispatch(ToggleDark)} className=Styles.toggler>
      <p>
        {ReasonReact.string(
           (state.dark ? {j|☑|j} : {j|☐|j}) ++ " Dark Mode",
         )}
      </p>
    </div>
  </React.Fragment>;
};

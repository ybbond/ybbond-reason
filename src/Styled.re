open Utils;

[@react.component]
let make = (~dark: bool) => {
  let backgroundColor = dark ? "#1b1b1b" : "#fdfdfd";
  let textColor = dark ? "#fdfdfd" : "#1b1b1b";
  let htmlStyle = "html { height: 100vh; background-color:" ++ backgroundColor ++ "; color:" ++ textColor  ++ "; }";
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
  let setStyle = htmlStyle ++ bodyStyle ++ miscStyle;

  <style dangerouslySetInnerHTML={dangerousHtml(setStyle)} />
};

type state = {
  opened: string,
  dark: bool,
};
type section =
  | Quest
  | Info
  | Contact;
type action =
  | ToggleDark
  | Open(section);

let convert = (s: section) =>
  switch (s) {
  | Quest => "quest"
  | Info => "info"
  | Contact => "contact"
  };
let initialState = {opened: "quest", dark: false};

[@react.component]
let make = () => {
  let (_, _) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | ToggleDark => {...state, dark: !state.dark}
        | Open(toOpen) => {...state, opened: convert(toOpen)}
        },
      initialState,
    );

  <React.Fragment>
    <Spoiler content={ReasonReact.string("Hello")} title="Yeay" />
  </React.Fragment>;
};

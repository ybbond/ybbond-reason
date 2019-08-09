type state = {
  opened: string,
  dark: bool,
};

type section = Quest | Info | Contact;
let convert = (s: section) =>
switch s {
  | Quest => "quest"
  | Info => "info"
  | Contact => "contact"
};

type action =
  | ToggleDark
  | Open((section));

let initialState = {opened: "quest", dark: false};

[@react.component]
let make = () => {
  let (state, _) =
    React.useReducer (
      (state, action) =>
        switch (action) {
          | ToggleDark => {...state, dark: !state.dark}
          | Open((toOpen)) => {...state, opened: convert( toOpen )};
        },
      initialState,
    );

  <div>
    {ReasonReact.createElement(span, _, state.opened)}
  </div>
}

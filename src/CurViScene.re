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

  let questContent =
    <ContentList
      content=[|
        {
          variant: Done,
          text:
            <span>
              {ReasonReact.string("Design apprentice at X-Graphic.")}
            </span>,
        },
        {
          variant: Done,
          text:
            <span>
              {ReasonReact.string("Field inspector at Touchten Games.")}
            </span>,
        },
        {
          variant: Done,
          text:
            <span>
              {ReasonReact.string("Reactive engineer at Vospay.")}
            </span>,
        },
        {
          variant: Progress,
          text:
            <span>
              {ReasonReact.string("Frontend Engineer at Kumparan.")}
            </span>,
        },
      |]
    />;

  let triviaContent =
    <ContentList
      content=[|
        {
          variant: Default,
          text:
            <span>
              {ReasonReact.string("Studied CS in Binus, never finished it.")}
            </span>,
        },
        {
          variant: Default,
          text: <span> {ReasonReact.string("Drinks coffee.")} </span>,
        },
        {
          variant: Default,
          text:
            <span>
              {ReasonReact.string("Loves moshing at indie band gigs.")}
            </span>,
        },
        {
          variant: Default,
          text: <span> {ReasonReact.string("Vim user.")} </span>,
        },
        {
          variant: Default,
          text: <span> {ReasonReact.string("Jakarta, Indonesia")} </span>,
        },
      |]
    />;

  let contactContent =
    <ContentList
      content=[|
        {
          variant: Default,
          text:
            <span>
              {ReasonReact.string("everywhere: ybbond or bandungpenting")}
            </span>,
        },
        {
          variant: Default,
          text:
            <span> {ReasonReact.string("bandungpenting@gmail.com")} </span>,
        },
        {
          variant: Default,
          text:
            <span>
              <Link href="https://www.instagram.com/ybbond" text="Instagram" />
              {ReasonReact.string(", ")}
              <Link href="https://github.com/ybbond" text="Github" />
              {ReasonReact.string(", ")}
              <Link href="https://twitter.com/bandungpenting" text="Twitter" />
              {ReasonReact.string(".")}
            </span>,
        },
      |]
    />;

  <React.Fragment>
    <Spoiler content=questContent title="Quests" />
    <Spoiler content=triviaContent title="Good to Know" />
    <Spoiler content=contactContent title="Find me" />
  </React.Fragment>;
};

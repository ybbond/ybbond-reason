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
              {ReasonReact.string("Design apprentice at ")}
              <Link href="https://www.xg.co.id" text="X-Graphic" />
              {ReasonReact.string(".")}
            </span>,
        },
        {
          variant: Done,
          text:
            <span>
              {ReasonReact.string("Quality Assurance at ")}
              <Link href="https://www.touchten.com" text="Touchten Games" />
              {ReasonReact.string(".")}
            </span>,
        },
        {
          variant: Done,
          text:
            <span>
              {ReasonReact.string("Reactive Engineer at ")}
              <Link href="https://vospay.id" text="Vospay" />
              {ReasonReact.string(".")}
            </span>,
        },
        {
          variant: Progress,
          text:
            <h5>
              {ReasonReact.string("Frontend Engineer at ")}
              <Link href="https://kumparan.com" text="kumparan" />
              {ReasonReact.string(".")}
            </h5>,
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
          text:
            <span>
              <Link text="Vim user" internal="uses" />
              {ReasonReact.string(".")}
            </span>,
        },
        {
          variant: Default,
          text:
            <span>
              {ReasonReact.string("from ")}
              <Link
                href="https://goo.gl/maps/gMGbA5juGAx"
                text="Jakarta, Indonesia"
              />
              {ReasonReact.string(".")}
            </span>,
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
              {ReasonReact.string("everywhere: ybbond or bandungpenting.")}
            </span>,
        },
        {
          variant: Default,
          text:
            <h5>
              <Link
                href="mailto:bandungpenting@gmail.com?subject=From%20ybbond.dev"
                text="bandungpenting@gmail.com"
              />
              {ReasonReact.string(".")}
            </h5>,
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

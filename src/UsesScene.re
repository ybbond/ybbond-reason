[@react.component]
let make = () => {
  <React.Fragment>
    <h3> {ReasonReact.string("Hardware and Platform")} </h3>
    <ContentList
      content=[|
        {
          variant: Default,
          text:
            <span>
              {ReasonReact.string("Macbook Pro 2018 13\" (Office)")}
            </span>,
        },
        {
          variant: Default,
          text:
            <span>
              {ReasonReact.string("Low-End PC with Manjaro Linux XFCE (Home)")}
            </span>,
        },
      |]
    />
    <h3> {ReasonReact.string("Code Editor")} </h3>
    <ContentList
      content=[|
        {
          variant: Default,
          text: <span> {ReasonReact.string("Neovim on Kitty")} </span>,
        },
        {
          variant: Default,
          text: <span> {ReasonReact.string("Visual Studio Code")} </span>,
        },
      |]
    />
    <h3> {ReasonReact.string("Terminal")} </h3>
    <ContentList
      content=[|
        {
          variant: Default,
          text: <span> {ReasonReact.string("Kitty")} </span>,
        },
        {
          variant: Default,
          text: <span> {ReasonReact.string("Fish Shell")} </span>,
        },
        {
          variant: Default,
          text: <span> {ReasonReact.string("Ranger File Manager")} </span>,
        },
        {
          variant: Default,
          text: <span> {ReasonReact.string("lazygit")} </span>,
        },
      |]
    />
  </React.Fragment>;
};

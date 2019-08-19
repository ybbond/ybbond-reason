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
  </React.Fragment>;
};

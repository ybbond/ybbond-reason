let handleClick = (internal, event) =>
  if (!ReactEvent.Mouse.defaultPrevented(event) && internal !== "") {
    ReactEvent.Mouse.preventDefault(event);
    ReasonReact.Router.push(internal);
  };

[@react.component]
let make = (~href="", ~text: string, ~internal="") =>
  <mark>
    <a
      href
      target="_blank"
      rel="noopener noreferrer"
      onClick={event => handleClick(internal, event)}>
      {ReasonReact.string(text)}
    </a>
  </mark>;

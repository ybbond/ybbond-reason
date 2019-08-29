[@react.component]
let make = () => {
  <React.Fragment>
    <p>
      {ReasonReact.string(
         "Poems have not been implemented on this web version :(",
       )}
    </p>
    <p>
      {ReasonReact.string("If you want to read them, ")}
      <Link text="click here!" href="https://ybbond.github.io" />
    </p>
    <p> {ReasonReact.string("Then, check the 'literature'.")} </p>
  </React.Fragment>;
};

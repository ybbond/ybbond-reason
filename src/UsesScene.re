[@react.component]
let make = () => {
  <React.Fragment>
    <h3> {ReasonReact.string("Platform")} </h3>
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
    <h3> {ReasonReact.string("Hardware")} </h3>
    <ContentList
      content=[|
        {
          variant: Default,
          text:
            <React.Fragment>
              <span>
                {ReasonReact.string("Ducky One 2 Mini Keyboard ")}
                <Link
                  text="image"
                  href="https://twitter.com/bandungpenting/status/1146845120618090497"
                />
              </span>
              <ContentList
                content=[|
                  {
                    variant: Default,
                    text:
                      <span>
                        {ReasonReact.string("Farewell gift from friends at ")}
                        <Link href="https://kodefox.com" text="Kodefox" />
                        {ReasonReact.string(" and ")}
                        <Link href="https://vospay.id" text="Vospay" />
                        {ReasonReact.string("!")}
                      </span>,
                  },
                |]
              />
            </React.Fragment>,
        },
      |]
    />
    <h3> {ReasonReact.string("Code Editor")} </h3>
    <ContentList
      content=[|
        {
          variant: Default,
          text:
            <span>
              {ReasonReact.string("Neovim ")}
              <Link
                text="image"
                href="https://twitter.com/bandungpenting/status/1162210601340305409"
              />
              {ReasonReact.string(" ")}
              <Link
                text="settings"
                href="https://gist.github.com/ybbond/16ee5000eeca727899eac43a4c20291c"
              />
            </span>,
        },
        {
          variant: Default,
          text:
            <span>
              {ReasonReact.string("Visual Studio Code ")}
              <Link
                text="settings"
                href="https://gist.github.com/ybbond/5838223bb0c11b355cdbaf35e1599895"
              />
            </span>,
        },
      |]
    />
    <h3> {ReasonReact.string("Terminal")} </h3>
    <ContentList
      content=[|
        {
          variant: Default,
          text:
            <span>
              {ReasonReact.string("tmux on Alacritty ")}
              <Link
                text="settings"
                href="https://gist.github.com/ybbond/26165e50f36a439b6b930607976a1e82"
              />
            </span>,
        },
        {
          variant: Default,
          text:
            <span>
              {ReasonReact.string("Kitty ")}
              <Link
                text="settings"
                href="https://gist.github.com/ybbond/25f8f04ce6f896ba19ecbbc10d4ba6fd"
              />
            </span>,
        },
        {
          variant: Default,
          text:
            <span>
              {ReasonReact.string("Z Shell (zsh) ")}
              <Link
                text="settings"
                href="https://gist.github.com/ybbond/e6f827f977248b5d9eda8e1c49da82e9"
              />
            </span>,
        },
        {
          variant: Default,
          text:
            <span>
              <Link text="Ranger" href="https://github.com/ranger/ranger" />
              {ReasonReact.string(" File Manager ")}
              <Link
                text="settings"
                href="https://gist.github.com/ybbond/99acda0e787683c9b3b43e32752806ad"
              />
            </span>,
        },
        {
          variant: Default,
          text:
            <span>
              <Link
                text="lazygit"
                href="https://github.com/jesseduffield/lazygit"
              />
            </span>,
        },
      |]
    />
  </React.Fragment>;
};

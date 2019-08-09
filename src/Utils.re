/* to enable require css file */
[@bs.val] external requireCSS: string => unit = "require";

/* to get Date.now */
[@bs.val] external currentTime: unit => int = "Date.now";

/* format a timestamp in seconds as relative humanised time sentence */
let fromNow = unixtime => {
  let delta = currentTime() / 1000 - unixtime;
  if (delta < 3600) {
    string_of_int(delta / 60) ++ " minutes ago";
  } else if (delta < 86400) {
    string_of_int(delta / 3600) ++ " hours ago";
  } else {
    string_of_int(delta / 86400) ++ " days ago";
  };
};

/* extras JS function */
[@bs.send] [@bs.return nullable]
external getAttribute: (Js.t('a), string) => option(string) = "getAttribute";

let dangerousHtml: string => Js.t('a) = html => {"__html": html};

let distanceFromBottom: unit => int =
  () => {
    let bodyClientHeight = [%raw "document.body.clientHeight"];
    let windowScrollY = [%raw "window.scrollY"];
    let windowInnerHeight = [%raw "window.innerHeight"];
    bodyClientHeight - (windowScrollY + windowInnerHeight);
  };

/* registerServiceWorker */
[@bs.module] external registerServiceWorker: unit => unit = "src/registerServiceWorker";

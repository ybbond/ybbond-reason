open Belt;

let apiBaseUrl = "https://api.github.com/users/ybbond/gists";

type gist_file_content = {
  filename: string,
  language: string,
  raw_url: string,
  size: int,
  type_: string,
};

type owner_type = {
  avatar_url: string,
  events_url: string,
  followers_url: string,
  following_url: string,
  gists_url: string,
  gravatar_id: string,
  html_url: string,
  id: int,
  login: string,
  node_id: string,
  organizations_url: string,
  received_events_url: string,
  repos_url: string,
  site_admin: bool,
  starred_url: string,
  subscriptions_url: string,
  type_: string,
  url: string,
};

type gist_files = Map.String.t(gist_file_content);

type gist_type = {
  comments: int,
  comments_url: string,
  commits_url: string,
  created_at: string,
  description: string,
  files: gist_files,
  forks_url: string,
  git_pull_url: string,
  git_push_url: string,
  html_url: string,
  id: string,
  node_id: string,
  owner: owner_type,
  public: bool,
  truncated: bool,
  updated_at: string,
  url: string,
};

module Decode = {
  let gistFileContent = (json): gist_file_content =>
    Json.Decode.{
      filename: json |> field("filename", string),
      language: json |> field("language", string),
      raw_url: json |> field("raw_url", string),
      size: json |> field("size", int),
      type_: json |> field("type", string),
    };

  let gistFiles = (json): gist_files =>
    Json.Decode.dict(gistFileContent, json)
    ->(Js.Dict.fromList())
    ->Map.String.fromArray;

  let gist = (json): gist_type =>
    Json.Decode.{
      comments: json |> field("comments", int),
      commits_url: json |> field("commits_url", string),
      commits_url: json |> field("commits_url", string),
      created_at: json |> field("created_at", string),
      description: json |> field("description", string),
      files: json |> field("files", gistFiles),
      forks_url: json |> field("forks_url", string),
      git_pull_url: json |> field("git_pull_url", string),
      git_push_url: json |> field("git_push_url", string),
      html_url: json |> field("html_url", string),
      id: json |> field("id", string),
      node_id: json |> field("node_id", string),
      owner,
      public: json |> field("public", bool),
      truncated: json |> field("truncated", bool),
      updated_at: json |> field("updated_at", string),
      url: json |> field("url", string),
    };
};

let fetchGist = () =>
  Js.Promise.(
    Fetch.fetch(apiBaseUrl)
    |> then_(Fetch.Response.json)
    |> then_(json => json |> Decode)
  );

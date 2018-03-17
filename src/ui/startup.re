type route =
| Home
| About
| NotFound;

type state = route;

type action =
| GoTo(route);

let component = ReasonReact.reducerComponent("Startup");

let mapUrl = (path) => {
    switch (path) {
        | ["/"] | [] => Home
        | ["about"] => About
        | _  => NotFound
    }
};

let getActiveClass = (activeRoute, route) => activeRoute == route ? "active" : "";

let make = (_children) => {

    ...component,
    initialState: () => Home,
    didMount: (_self) => ReasonReact.Update({mapUrl(ReasonReact.Router.dangerouslyGetInitialUrl().path)}),
    subscriptions: (self) => [
            Sub(
            () => ReasonReact.Router.watchUrl(url => self.send(GoTo(mapUrl(url.path)))),
                ReasonReact.Router.unwatchUrl
            )
        ],
    reducer: (action, _state) => {
        switch (action) {
            | GoTo(route) => ReasonReact.Update({route})
        }
    },
    render: self => {
        <div className="App">
            <Header>
                <div className={"title"}>
                    {"Sliding Puzzle (ReasonReact)" |> Utils.text}
                </div>
                <div className="navigation">
                    <ul>
                        <li>
                            <Router.Link to_="/" activeClass=getActiveClass(self.state, Home)>{"Home" |> Utils.text}</Router.Link>
                        </li>
                        <li>
                            <Router.Link to_="/about" activeClass=getActiveClass(self.state, About) >{"About" |> Utils.text}</Router.Link>
                        </li>
                    </ul>
                </div>
            </Header>
            <Content>
                (switch (self.state) {
                    | Home => <Home />
                    | About => <About />
                    | _ => "404" |> Utils.text
                })
            </Content>
        </div>
    }

}

let component = ReasonReact.statelessComponent("A");

let make = (~href, ~target="_self", children) => {
    ...component,
    render: _self => {

        switch(target) {
            | "_blank" => <a href=href target=target rel="noopener noreferrer">{children |> ReasonReact.arrayToElement}</a>
            | _ => <a href=href target=target >{children |> ReasonReact.arrayToElement}</a>
        }
    }
};
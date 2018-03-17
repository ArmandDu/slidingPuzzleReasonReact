[%bs.raw {|require('./header.css')|}];


let component = ReasonReact.statelessComponent("Header");

let make = (children) => {
    ...component,
    render: _self => {
        <div className="Header" >
            {children |> ReasonReact.arrayToElement}
        </div>
    }
};

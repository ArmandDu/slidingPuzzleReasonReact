[%bs.raw {|require('./content.css')|}];


let component = ReasonReact.statelessComponent("Content");

let make = (children) => {
    ...component,
    render: _self => {
        <div className="Content">
            children[0]
        </div>
    }
};

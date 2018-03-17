let text = (str) => ReasonReact.stringToElement(str);

module Link = {

    let handleClick = (to_) => (event, _self) => {
        event |> ReactEventRe.Synthetic.preventDefault;
        ReasonReact.Router.push(to_);
    };

    let component = ReasonReact.statelessComponent("Link");

    let make = (~to_, ~activeClass, children) => {
        ...component,
        render: self => {
                <a className=activeClass href=to_ onClick=self.handle(handleClick(to_))>children[0]</a>
        }
    };
};
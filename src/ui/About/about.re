let component = ReasonReact.statelessComponent("About");


let make = (_children) => {
    ...component,
    render: _self => {
        <div>
                <section>
                    <h2>{"About"|> Utils.text}</h2>
                </section>
                <section>
                    <p>{"This project was made by ArmandDu." |> Utils.text}</p>
                    <p>{"You can find the source code for the React version here: " |> Utils.text}
                        <A href={"https://github.com/ArmandDu/slidingPuzzleReact"} target={"_blank"}>{"ArmandDu/slidingPuzzleReact" |> Utils.text}</A>
                        <br/>
                        {"and the ReasonReact version here: " |> Utils.text}
                        <A href={"https://github.com/ArmandDu/slidingPuzzleReasonReact"} target={"_blank"}>{"ArmandDu/slidingPuzzleReasonReact" |> Utils.text}</A>
                    </p>
                </section>
                <secion>
                    <h4>{"Motivation" |> Utils.text}</h4>
                    <p>{"After finding about " |> Utils.text}
                       <A href="https://reasonml.github.io/reason-react/" target="_blank">{"ReasonReact" |> Utils.text}</A>
                       {", I wanted to give it a try and see how it looked." |> Utils.text}</p>
                    <p>{"I then decided to see how I could implement a \"reducerComponent\" pattern in React, this is why I have the same project in both languages." |> Utils.text}</p>
                    <p/>
                    <p>{"I also wrote a blog article about this project here:" |> Utils.text}
                        <A href={"https://blog.armanddu.com/tag/sliding-puzzle/ "} target={"_blank"}>{"blog.armanddu.com/tag/sliding-puzzle" |> Utils.text}</A>
                    </p>
                </secion>
        </div>
    }
};
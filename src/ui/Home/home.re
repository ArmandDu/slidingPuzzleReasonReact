let component = ReasonReact.statelessComponent("Home");


let make = (_children) => {
    ...component,
    render: _self => {
        <div>
             <section>
                <h2>{"ReasonReact - Sliding Game" |> Utils.text}</h2>
                <p>
                    <A href="https://puzzle.apptize.fr/?v=react">{"React version"|> Utils.text}</A>
                </p>
             </section>
             <section>
                <p>{"A small sliding puzzle game made with React & ReasonReact." |> Utils.text}</p>
                <p>
                    {"This is a small project made to learn new patterns in " |> Utils.text}
                    <A href="https://reactjs.org/" target="_blank">{"React"|> Utils.text}</A>
                    {" and try out " |> Utils.text}
                    <A href="https://reasonml.github.io/reason-react/" target="_blank">{"ReasonReact"|> Utils.text}</A>
                    {". Enjoy." |> Utils.text}
                </p>
             </section>
             <section>
                <Newgame />
             </section>
        </div>
    }
};
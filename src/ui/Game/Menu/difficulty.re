type difficulty =
| Easy
| Medium
| Hard
| Expert;


let mapString = (d) => {
    switch (d) {
        | Easy => "easy"
        | Medium => "medium"
        | Hard => "hard"
        | Expert => "expert"
    }
};

let mapDifficulty = (d) => {
    switch (d) {
        | "easy" => Easy
        | "medium" => Medium
        | "hard" => Hard
        | "expert" => Expert
        | _ => Medium
    }
};

let handleChange = handler => e => {

  let value = () => ReactDOMRe.domElementToObj(ReactEventRe.Form.target(e))##value;

  handler(mapDifficulty(value()));
};

let component = ReasonReact.statelessComponent("Difficulty");

let make = (~difficulty, ~onSelect, _children) => {
          ...component,
          render: _self => {
              <div className="SelectDifficulty">
                  <select value=mapString(difficulty) onChange=handleChange(onSelect)>
                    <option value="easy">{"Easy"|>Utils.text}</option>
                    <option value="medium">{"Medium"|>Utils.text}</option>
                    <option value="hard">{"Hard"|>Utils.text}</option>
                    <option value="expert">{"Expert"|>Utils.text}</option>
                  </select>
              </div>
          }
};
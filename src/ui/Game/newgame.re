[@bs.module] external dog : string = "../../assets/puzzles/doge.png";
[@bs.module] external cat : string = "../../assets/puzzles/cat.jpg";
[@bs.module] external tabasco : string = "../../assets/puzzles/tabasco.JPG";

type image = (string, string);

type state = { difficulty: Difficulty.difficulty, image: option(image) };

type action =
| SelectImage(image)
| SelectNone
| SetDifficulty(Difficulty.difficulty);


let component = ReasonReact.reducerComponent("Newgame");

let imageBank = () => [|("1", dog),
                        ("2", cat),
                        ("3", tabasco)|];


let make = (_children) => {

    let getOptionalId = image => switch(image) {
        | Some((id, _)) => id
        | None => ""
    };

    let mapDifficulty = difficulty => switch(difficulty) {
        | Difficulty.Easy => (3, 3)
        | Difficulty.Medium => (5, 5)
        | Difficulty.Hard => (9, 9)
        | Difficulty.Expert => (12, 12)
    };

    {
        ...component,
        initialState: () => {difficulty: Difficulty.Medium, image: None },
        reducer: (action, state) => {
            switch (action) {
                | SelectImage(image) => ReasonReact.Update({...state, image: Some(image)})
                | SelectNone => ReasonReact.Update({...state, image: None})
                | SetDifficulty(difficulty) => ReasonReact.Update({...state, difficulty})
            };
        },
        render: self => {
            let handleSelectDifficulty = (difficulty: Difficulty.difficulty) => self.send(SetDifficulty(difficulty));

            {
                    (switch (self.state.image, mapDifficulty(self.state.difficulty)) {
                        | (Some((_, url)), (x, y)) => (

                            <Game x=x y=y url=url onGoBack={_e => self.send(SelectNone)}/>

                        )
                        | _ => (
                            <Menu activeId={self.state.image |> getOptionalId }
                                  bank=imageBank()
                                  difficulty=self.state.difficulty
                                  onSelectDifficulty=handleSelectDifficulty
                                  onSelectImage={(image, _) => self.send(SelectImage(image))} />
                        )
                    })
            }
        }
    }
};
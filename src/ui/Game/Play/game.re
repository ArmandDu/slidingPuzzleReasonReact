[%bs.raw {|require('./Play.css')|}];

type state = { pieces: array(int), pivot: int };

type action =
| SWAP_PIECES(int, int);



let component = ReasonReact.reducerComponent("game");

let make = (~x, ~y, ~url, ~onGoBack, _children) => {

        ...component,
        initialState: () => {
            let pivot = Random.int(x*y);

            { pivot: pivot, pieces: Setup.getShuffledPieces(x, y, x+y * Random.int(x*y), pivot) }
        },
        reducer: (action: action, state) => {
            switch (action) {
              | SWAP_PIECES(pivot, piece) => {

                    let pivotIndex = state.pieces |> Utils.findIndexArray(a => a == pivot);
                    let pieceIndex = state.pieces |> Utils.findIndexArray(a => a == piece);
                    let dist = Utils.distanceIndex(x, y, pivotIndex, pieceIndex);

                    switch (dist) {
                        | 1. => ReasonReact.Update({...state, pieces: Utils.swapArray(pivotIndex, pieceIndex, state.pieces)})
                        | _ =>  ReasonReact.NoUpdate
                    };
                };
            };
         },
        render: self => {

            let handleSwap = (pivot, piece) => self.send(SWAP_PIECES(pivot, piece));
            let won = () => self.state.pieces
                            |> Array.to_list
                            |> List.mapi((i, a) => (a, i))
                            |> List.for_all(((i, a)) => i == a);


            <div className="Play">
                {switch (won()) {
                    | true => {
                        <div>
                            <img src=url alt=url />
                        </div>
                    }
                    | false => {
                        <Puzzle url=url
                                pieces=self.state.pieces
                                pivot=self.state.pivot
                                onSwap=handleSwap
                                x=x y=y />
                    }
                }}
                <button onClick=onGoBack>{"Quit" |> Utils.text}</button>
            </div>
        }
};

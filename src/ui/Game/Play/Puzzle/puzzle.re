[%bs.raw {|require('./Puzzle.css')|}];

let component = ReasonReact.statelessComponent("puzzle");


let make = (~pieces, ~x, ~y, ~url, ~pivot, ~onSwap, _children) => {
    ...component,
    render: _self => {

        let mapPiece = (i, j, piece) => {
                <Piece key=string_of_int(piece)
                       url=url
                       pivot=pivot
                       piece=piece
                       onClick={(_) => onSwap(pivot, piece)}
                       x=x y=y/>
            };

        let mapRow = (i, row) => {
            <div key=string_of_int(i) className="Row">
                (
                    row
                    |> Array.mapi(mapPiece(i))
                    |> ReasonReact.arrayToElement
                )
            </div>
        };


        <div className="Puzzle">
         (
            Utils.chunkArray(x, pieces, [||])
            |> Array.mapi(mapRow)
            |> ReasonReact.arrayToElement
         )
        </div>
    }
}
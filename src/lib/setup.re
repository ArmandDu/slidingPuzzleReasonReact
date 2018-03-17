
let rec shufflePieces = (w, h, count, pivot: int, array) => switch (count) {
    | 0 => array
    | c => {

        let pivotIndex = array |> Utils.findIndexArray(a => a == pivot);
        let (dx, dy) = switch(Random.int(4)) {
            | 0 => (0, 1)
            | 1 => (0, -1)
            | 2 => (1, 0)
            | 3 => (-1, 0)
        };
        let pieceIndex = switch (pivotIndex + (dx+dy*h)) {
            | i when i < 0 => pivot
            | i when i >= w*h => pivot
            | i => i
        };
        let newArray = Utils.swapArray(pivotIndex, pieceIndex, array);

        let win = newArray
                  |> Array.to_list
                  |> List.mapi((i, a) => (a, i))
                  |> List.for_all(((i, a)) => i == a);

        let newCount = switch(win) {
            | true => c
            | false => c - 1
        };

        shufflePieces(w, h, newCount, pivot, newArray)
    }
};

let getShuffledPieces = (x, y, c, pivot) => Array.init(x*y, (i: int) => (i: int)) |> shufflePieces(x, y, c, pivot);

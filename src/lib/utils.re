let text = (str) => ReasonReact.stringToElement(str);


let sortArray = predicate => arr => {
    arr |> Array.sort(predicate);
    arr;
};

let shuffleArray = lst => lst
    |> Array.map(e => (e, Random.int(1000) - 1))
    |> sortArray(((_, a), (_, b)) => compare(a, b))
    |> Array.map((t) => fst(t));

let rec chunkArray = (size, src, dst) => {
    let len = src |> Array.length;

    switch (len) {
        | 0 => dst
        | s when s < size => Array.append(dst, [|src|])
        | s when s >= size => chunkArray(size, Array.sub(src, size, len - size), Array.append(dst, [|Array.sub(src, 0, size)|]))
    };
};

let findIndexArray = predicate => arr => arr
    |> Array.mapi((i, a) => (i, a))
    |> Array.to_list
    |> List.find(((_, a)) => predicate(a))
    |> fst;


let swapArray = (i, j, array) => {
    let a = Array.get(array, i);
    let b = Array.get(array, j);

    Array.set(array, j, a);
    Array.set(array, i, b);

    array;
};

let distance = ((x1, y1), (x2, y2)) => sqrt( float_of_int((x2-x1))**2.0 +. float_of_int((y2-y1))**2.0 );

let distanceIndex = (w, h) => (a, b) => (distance((a mod w, a / h), (b mod w, b / h)));


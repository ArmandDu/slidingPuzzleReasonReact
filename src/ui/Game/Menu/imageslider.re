[%bs.raw {|require('./Menu.css')|}];

let component = ReasonReact.statelessComponent("ImagesSlider");

let make = (~onSelect, ~bank, ~activeId=?, _children) => {


    let mapImage = ((id, url)) => {

        <div className="PuzzlePreview"
             key=id
             style=ReactDOMRe.Style.make(~backgroundImage="url("++url++")", ())
             onClick=onSelect((id, url))/>
    };

    {
    ...component,
    render: _self => {

        <div className="SelectPuzzle" >
            (
            bank
            |> Array.map(mapImage)
            |> ReasonReact.arrayToElement
            )
        </div>
       }
    }
};
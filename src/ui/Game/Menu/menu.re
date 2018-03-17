[%bs.raw {|require('./Menu.css')|}];


let component = ReasonReact.statelessComponent("Menu");

let make = (~onSelectImage, ~onSelectDifficulty, ~bank, ~activeId, ~difficulty, _children) => {
    ...component,
    render: _self => {
        <div className="Menu">
            <Imageslider activeId=activeId
                         onSelect=onSelectImage
                         bank=bank />

            <Difficulty difficulty=difficulty onSelect=onSelectDifficulty />
        </div>
    }
};
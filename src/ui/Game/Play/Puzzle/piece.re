let component = ReasonReact.statelessComponent("puzzle");

let style = (~width, ~height, ~left, ~top, ~url) => ReactDOMRe.Style.make(~width=string_of_int(width)++"px",
                                                             ~height=string_of_int(height)++"px",
                                                             ~backgroundSize="600px 600px",
                                                             ~backgroundRepeat="no-repeat",
                                                             ~backgroundPosition="-"++string_of_int(left)++"px -"++string_of_int(top)++"px",
                                                             ~backgroundImage="url("++url++")", ());

let pivotStyle = (~width, ~height) => ReactDOMRe.Style.make(~width=string_of_int(width)++"px",
                                                            ~height=string_of_int(height)++"px",
                                                            ~backgroundColor="#a0a0a0", ());

let make = (~url, ~pivot, ~piece, ~onClick, ~x, ~y, _children) => {
    ...component,
    render: _self => {

    let chunkWidth = 600 / x;
    let chunkHeight = 600 / y;
    let i = piece mod x;
    let j = piece / y;

     <div className="Piece">
        (
            switch (pivot) {
                | p when p == piece => <div style=pivotStyle(~width=chunkWidth, ~height=chunkHeight) />
                | _ => <div onClick=onClick
                            className="Debug"
                            style=style(~width=chunkWidth,
                                        ~height=chunkHeight,
                                        ~left={i*chunkWidth},
                                        ~top={j*chunkHeight},
                                        ~url=url)>
                            </div>
            }
        )
     </div>

    }
}
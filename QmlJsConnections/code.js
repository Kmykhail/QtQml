var Root
var Box

function startup(root, box, area) {
    Root = root
    Box = box
}

function calcPosition(root, obj) {
    const max = Root.width - Box.width;
    Box.x = (!Box.x) ? max : 0;
}

function swapColor(obj){
    return obj.pressed ? "yellow" : "grey";
}

function clicked(mouse) {
    console.log("jsClickHandler");
    calcPosition();
}

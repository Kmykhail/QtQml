function calcPosition(root, obj) {
    const max = root.width - obj.width;
    obj.x = (!obj.x) ? max : 0;
}

function swapColor(obj){
    return obj.pressed ? "yellow" : "grey";
}

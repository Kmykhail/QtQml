import QtQuick
import QtQuick.Controls

Item {
    id: root
    signal clicked(int value)

    Column {
        id: col
        Grid {
            id: grid
            columns: 3
            rows: 4
            spacing: 5
        }
    }

    function doClicked(value) {
        console.log(value);
        clicked(value);
    }

    Component.onCompleted: {
        console.log("NumberPad completed");
        for (var i = 0, num = 0; i < 10; i++, num++) {
            switch(i) {
                case 0: // first row of numPad(7, 8 , 9)
                    num = 7;
                    break;
                case 3: // second row of numPad(4, 5, 6)
                    num = 4;
                    break;
                case 6: // third row of numPad(1, 2, 3)
                    num = 1;
                    break;
                case 9: // last row of numPad(0)
                    num = 0;
                    break;
                default:
                    break;
            }

            var btn = Qt.createQmlObject('import QtQuick 2.0;\n
                                          import QtQuick.Controls; Button {id: btn' + i + ';\n
                                                                           onClicked: doClicked(' + num + ')}',
                                         grid,
                                         "DynamicallyLoaded");
            btn.width = 40;
            btn.height = 40;
            btn.text = num;
        }

        // set last button - 0
        var obj = grid.children[grid.children.length - 1];
        obj.parent = col;
        obj.width = (40 * grid.columns) + 10;
    }
}

import QtQuick
import QtQuick.Window

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Item {
        id: jsCode
        function calcPosition() {
            const max = mainWindow.width - box.width;
            box.x = (!box.x) ? max : 0;
        }
    }

    Rectangle {
        id: box
        x: 0
        y: (mainWindow.height / 2) - (box.height / 2)
        width: 100
        height: 100
        color: swapColor()

        function swapColor() {
            return mArea.pressed ? "yellow" : "grey";
        }

        MouseArea {
            id: mArea
            anchors.fill: parent
            onClicked: jsCode.calcPosition()
        }

        Component.onCompleted: {
            console.error("root: ", mainWindow, mainWindow.width, mainWindow.height);
        }
    }
}

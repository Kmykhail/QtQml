import QtQuick
import QtQuick.Window
import "code.js" as Code

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: box
        x: A
        y: (mainWindow.height / 2) - (box.height / 2)
        width: 100
        height: 100
        color: Code.swapColor(mArea)

        MouseArea {
            id: mArea
            anchors.fill: parent
        }
    }

    Component.onCompleted: {
        Code.startup(mainWindow, box, mArea);
        mArea.clicked.connect(Code.clicked);
    }
}

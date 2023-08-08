import QtQuick
import QtQuick.Controls
import QtQuick.Window

import "code.js" as Code

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Label {
        id: label
        font.pixelSize: 40
        x: (parent.width / 2) - (label.width / 2)
        y: (parent.height / 2) - (label.height / 2)
        color: "black"
        text: "0"
    }

    Button {
        id: btn
        width: 80
        height: 40
        anchors {
            top: label.bottom
            topMargin: 10
        }
        x: (parent.width / 2) - (btn.width / 2)
        onClicked: {
            label.text = Code.random();
        }
        text: "Click me"
    }
}

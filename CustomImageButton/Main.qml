import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        id: column
        x: 269
        y: 130
        width: 102
        height: 221
        spacing: 10

        CoolButton {
            id: coolButton
            width: 100
            height: 100
            source: "qrc:/images/images/upArrow.png"
            onClicked:  {
                console.log("Up clicked");
            }
        }

        CoolButton {
            id: coolButton1
            width: 100
            height: 100
            source: "qrc:/images/images/downArrow.png"
            onClicked: {
                console.log("Down clicked");
            }
        }
    }
}

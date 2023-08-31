import QtQuick
import QtQuick.Controls

Item {
    id: colorDelegate
    width: 180
    height: 40
    Row {
        spacing: 5

        Rectangle {
            anchors.verticalCenter: parent.verticalCenter
            width: 10
            height: 10
            border.color: "black"
            border.width: 1
            color: code
        }

        Text {
            text: name
            verticalAlignment: Text.AlignVCenter
        }
    }
}

import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    
    Column {
        id: column
        width: 200
        height: 264
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: 0
        spacing: 25
        anchors.horizontalCenter: parent.horizontalCenter
        
        Label {
            id: label
            text: qsTr("Label")
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
        }

        NumberPad {
            id: numPad
            width: 100
            height: 100
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: (value) => label.text = value
        }
    }
}

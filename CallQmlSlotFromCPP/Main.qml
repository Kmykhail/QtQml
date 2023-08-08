import QtQuick
import QtQuick.Controls 2.0
import QtQuick.Window

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    color: "grey"

    Connections {
        target: testing
        function onDateChanged(display) {
            dateInfo.text = display;
        }
    }

    Column {
        id: column
        width: 250
        height: 150
        spacing: 10
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Label {
            id: dateInfo
            font.pixelSize: 25
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Status"
            color: "black"
        }

        Row {
            id: row
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                id: startBtn
                width: 80
                height: 40
                text: "Start"
                onClicked: {
                    // launch date
                    testing.start();
                }
            }

            Button {
                id: stopBtn
                width: 80
                height: 40
                text: "Stop"
                onClicked: {
                    // stop date
                    testing.stop();
                }
            }
        }
    }
}

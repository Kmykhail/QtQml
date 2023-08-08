import QtQuick
import QtQuick.Controls 2.0
import QtQuick.Window
import test 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    color: "grey"

    Column {
        id: column
        width: 250
        height: 150
        spacing: 10
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Label {
            id: statusInfo
            font.pixelSize: 25
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Status"
            color: "black"
        }

        Test {
            id: test
            onStatus: {
                statusInfo.text = data;
            }
        }

        Row {
            id: row
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                id: startBtn
                width: 80
                height: 40
                text: "Generate"
                onClicked: {
                    test.generateRandom();
                }
            }
        }
    }
}

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
        height: 178
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter

        Label {
            id: sqftStatus
            text: qsTr("0 sqft")
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 25
            font.bold: true
        }

        Grid {
            id: grid
            width: 400
            height: 400
            rows: 3
            columns: 2
            spacing: 10

            Label {
                id: label1
                text: qsTr("Width")
            }

            SpinBox {
                id: spWidth
                width: 125
                height: 30
                onValueChanged: calc()
            }

            Label {
                id: label2
                text: qsTr("Height")
            }

            SpinBox {
                id: spHeight
                width: 125
                height: 30
                onValueChanged: calc()
            }
        }
    }

    function calc() {
        sqftStatus.text = spWidth.value * spHeight.value;
    }
}

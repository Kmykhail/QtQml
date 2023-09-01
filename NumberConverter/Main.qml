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
        width: 236
        height: 224
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10

        Grid {
            id: grid
            width: 200
            height: 129
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 20
            rows: 3
            columns: 2

            Label {
                id: lblType
                text: qsTr("Type")
            }

            ComboBox {
                id: comboBox
                model: ListModel{
                    ListElement {text: "inches to feet"}
                    ListElement {text: "inches to cm"}
                }
            }

            Label {
                id: lblFrom
                text: qsTr("From")
            }

            TextField {
                id: input
                placeholderText: qsTr("Text Field")
            }

            Label {
                id: lblResultText
                text: qsTr("Result")
            }

            Label {
                id: lblResult
                font.pixelSize: 15
                font.bold: true
            }
        }

        Button {
            id: btn
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: grid.bottom
            anchors.topMargin: 10
            text: qsTr("Convert")
            onClicked: convertMeasurement(input.text)
        }
    }

    function convertMeasurement(value) {
        console.error(value);
        if (comboBox.currentValue === "inches to feet") {
            lblResult.text = value / 12;
        } else if (comboBox.currentValue === "inches to cm") {
            lblResult.text = value * 2.54;
        }
    }
}

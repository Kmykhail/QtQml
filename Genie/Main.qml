import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        width: 200
        height: 182
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 20

        Label {
            id: lblStatus
            anchors.horizontalCenter: parent.horizontalCenter
            text: "test"
            font.bold: true
            font.pixelSize: 22
            color: "black"
        }

        RangeSlider {
            id: rSlider
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            from: 1
            to: 100
            first.value: 25
            second.value: 75
            stepSize: 1

            first.onValueChanged: {
                lblStatus.text = Math.round(first.value) + " to " + Math.round(second.value);
            }
            second.onValueChanged: {
                lblStatus.text = Math.round(first.value) + " to " + Math.round(second.value);
            }
        }

        Button {
            id: btn
            width: parent.width / 2
            height: 40
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Generate")
            onClicked: {
                generatorStatus.text = numberGenerator(Math.round(rSlider.first.value), Math.round(rSlider.second.value));
            }
        }

        Label {
            id: generatorStatus
            anchors.horizontalCenter: parent.horizontalCenter
            font.bold: true
            font.pixelSize: 30
            color: "black"
            text: qsTr("Move range and/or click button")
        }
    }

    function numberGenerator(min, max) {
        var number = Math.floor(Math.random() * (max - min + 1) + min);
        return number;
    }
}

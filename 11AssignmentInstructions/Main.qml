import QtQuick
import QtQuick.Window
import QtQuick.Controls
import My.Cat 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        width: 200
        height: 300
        spacing: 10

        Cat {
            id: cat
            onNameChanged: {
                lblText.text = cat.name
                popup.open();
            }

            onMeow: {
                lblText.text = "MEOW"
                popup.open();
            }
        }

        Popup {
            id: popup
            width: 80
            height: 40
            anchors.centerIn: parent
            background: Rectangle{
                color: "white"
                border.width: 1
            }

            Label {
                id: lblText
                anchors.centerIn: parent
                color: "black"
            }
        }

        Label {
            id: lbl
            text: qsTr("Name")
            color: "black"
        }

        TextField {
            id: name
            width: parent.width
            placeholderText: qsTr("Enter name")
            color: "black"
            background: Rectangle {
                anchors.fill: parent
                color: "white"
                border.width: 1
            }
        }

        Button {
            id: saveNameBtn
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Save")
            onClicked: {
                cat.name = name.text
            }
        }

        Button {
            id: callBtn
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Call")
            onClicked: {
                cat.call();
            }
        }
    }

}

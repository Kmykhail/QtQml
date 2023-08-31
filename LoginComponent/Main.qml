import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Login {
        id: login
        width: 196
        height: 128
        anchors.centerIn: parent
        onSubmit: (login, password) => {
            console.log("login:", login, ",password:", password);
            name.text = login;
            popup.open();
        }
    }

    Popup {
        id: popup
        anchors.centerIn: parent
        modal: true
        focus: true
        closePolicy: Popup.CloseOnPressOutside
        Text {
            id: name
            width: 200
            height: 200
        }
    }
}

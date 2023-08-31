import QtQuick
import QtQuick.Controls

Item {
    id: root
    signal submit(string login, string password)

    Column {
        id: usernameCln
        spacing: 5
        anchors.horizontalCenter: parent.horizontalCenter
        Label {
            id: usernameLbl
            text: qsTr("Username")
        }

        TextField {
            id: usernameField
            width: 150
        }
    }

    Column {
        id: passwordCln
        spacing: 5
        anchors {
            top: usernameCln.bottom
            horizontalCenter: parent.horizontalCenter
            topMargin: 20
        }
        Label {
            id: passwordLbl
            text: qsTr("Password")
        }

        TextField {
            id: passwordField
            width: 150
            echoMode: TextInput.Password
        }
    }

    Row {
        id: btnRow
        anchors {
            top: passwordCln.bottom
            horizontalCenter: parent.horizontalCenter
            topMargin: 10
        }

        Button {
            id: button
            text: qsTr("Submit")
            onClicked: {
                submit(usernameField.text, passwordField.text);
            }
        }
    }
}

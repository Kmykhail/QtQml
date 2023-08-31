import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ListView {
        id: lstView
        anchors.fill: parent
        anchors.margins: 20
        model: ColorModel{}
        delegate: ColorDelegate{}
    }
}

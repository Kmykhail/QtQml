import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property var meals: ["Borsch", "Varenyky", "Chicken Kiev", "Holubtsi", "Banosh", "Potato pancakes", "Salo"]

    MouseArea {
        id: area
        anchors.fill: parent
        onClicked: {
            opacityAni.start()
        }
    }

    Label {
        id: lblPlace
        anchors.centerIn: parent
        font.pixelSize: 25
        color: "black"
        text: qsTr("Tap me")
    }

    SequentialAnimation {
        id: startAni
        running: true
        loops: Animation.Infinite
        NumberAnimation {target: lblPlace; property: "font.pixelSize"; to: 45; duration: 1000}
        NumberAnimation {target: lblPlace; property: "font.pixelSize"; to: 25; duration: 1000}
    }

    OpacityAnimator {
        id: opacityAni
        target: lblPlace
        from: 1
        to: 0
        duration: 200
        onFinished: pick()
    }

    ParallelAnimation {
        id: selectorAni

        NumberAnimation {
            target: lblPlace
            property: "font.pixelSize"
            from: 0
            to: 45
            duration: 2000
        }


        OpacityAnimator {
            target: lblPlace
            from: 0
            to: 1
            duration: 2000
        }

        RotationAnimation {
            target: lblPlace
            from: 0
            to: 1
            duration: 2000
            direction: RotationAnimation.Counterclockwise
        }
    }

    function pick() {
        lblPlace.text = meals[Math.floor(Math.random() * meals.length)];
        selectorAni.start();
    }
}























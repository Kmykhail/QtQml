import QtQuick
import QtQuick.Window
import QtQuick.Controls
import My.Machine 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
//    color: "grey"

    Machine {
        id: machine

        Component.onCompleted: {
            startBtn.enabled = true;
            stopBtn.enabled = false;
            pauseBtn.enabled = false;
            resumeBtn.enabled = false;
        }

        onStarted: {
            startBtn.enabled = false;
            stopBtn.enabled = true;
            pauseBtn.enabled = true;
            resumeBtn.enabled = false;
        }

        onPaused: {
            startBtn.enabled = false;
            stopBtn.enabled = true;
            pauseBtn.enabled = false;
            resumeBtn.enabled = true;
        }

        onResummed: {
            startBtn.enabled = false;
            stopBtn.enabled = true;
            pauseBtn.enabled = true;
            resumeBtn.enabled = false;
        }

        onStopped: {
            startBtn.enabled = true;
            stopBtn.enabled = false;
            pauseBtn.enabled = false;
            resumeBtn.enabled = false;
            pb.value = 0.0;
            lbl.text = "Stopped"
        }

        onProgress: {
            pb.value = workload;
            lbl.text = "Progress: " + workload + "%";
        }
    }

    Column {
        id: clmn
        width: 434
        height: 200
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10
        Label {
            id: lbl
            text: qsTr("Status")
            color: "black"
        }

        ProgressBar {
            id: pb
            width: parent.width
            height: 10
            anchors.horizontalCenter: parent.horizontalCenter
            to: 100
            background: Rectangle {
                anchors.fill: parent
                color: "lightgreen"
                radius: 4
                border.width: 1
                border.color: "red"
            }
        }

        Row {
            id: rw
            width: 200
            height: 100
            spacing: 10
            Button {
                id: startBtn
                text: qsTr("Start")
                onClicked: {
                    machine.start();
                }
            }

            Button {
                id: pauseBtn
                text: qsTr("Pause")
                onClicked: {
                    machine.pause();
                }
            }

            Button {
                id: resumeBtn
                text: qsTr("Resume")
                onClicked: {
                    machine.resume();
                }
            }

            Button {
                id: stopBtn
                text: qsTr("Stop")
                onClicked: {
                    machine.stop();
                }
            }
        }
    }
}

import QtQuick
import QtQuick.Controls

ComboBox {
    id: root
    model: ["red", "blue", "yellow", "green", "orange"]
    delegate: ItemDelegate {
        width: root.width
        highlighted: highlightedIndex === index
        contentItem: Row {
            spacing: 5
            Rectangle {
                anchors.verticalCenter: parent.verticalCenter
                width: 10
                height: 10
                color: modelData
            }

            Text {
                text: modelData
                verticalAlignment: Text.AlignVCenter
            }
        }
    }
}

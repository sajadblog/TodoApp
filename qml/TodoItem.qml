import QtQuick 2.12
import QtQuick.Controls 2.12

Item{
    id: root
    signal removeMe()
    signal editMe()

    height: priorityButton.height + innerSpace.anchors.margins
    Rectangle {
        anchors.fill: parent
        anchors.rightMargin: rightToolBarPanel.width + innerSpace.anchors.margins
        border.width: 2
        border.color: "Gold"
        color: background
        Row{
            spacing: innerSpace.anchors.margins
            anchors.fill: parent
            anchors.rightMargin: innerSpace.anchors.margins
            TextField{
                width: parent.width - priorityButton.width - seperator.width - (parent.children.length - 1) * parent.spacing
                height: parent.height
                background: null
                text: description
                onTextChanged: description = text
                Component.onCompleted: text = description
            }
            Rectangle{
                id: seperator
                height: parent.height
                width: 2
                border.color: "Gold"
                border.width: 1
            }
            ComboBox{
                id: priorityButton
                width: 100
                height: 30
                anchors.verticalCenter: parent.verticalCenter
                model: ["NONE", "LOW", "MEDIUM", "HIGH"]
                currentIndex: priority
                background: Rectangle {color: "#e0e0e0";}
                indicator: Item{}
                onCurrentIndexChanged: priority = currentIndex
            }
        }
    }
    Item {
        id: rightToolBarPanel
        anchors.right: parent.right
        width: removeButton.width + completedCheckBox.width + editButton.width + (rightToolBarRow.children.length - 1) * rightToolBarRow.spacing
        Row{
            id: rightToolBarRow
            spacing: innerSpace.anchors.margins
            CheckBox{
                id: completedCheckBox
                checkState: completed ? Qt.Checked : Qt.Unchecked
                onCheckStateChanged: completed = checkState == Qt.Checked
            }
            Button{
                id: removeButton
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("Trash")
                background: Rectangle {color: "lightBlue";}
                onClicked: root.removeMe()
            }
            Image{
                id: editButton
                anchors.verticalCenter: parent.verticalCenter
                source: "qrc:/resources/edit.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked:  root.editMe()
                }
            }
        }
    }
}

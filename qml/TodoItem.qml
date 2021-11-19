import QtQuick 2.12
import QtQuick.Controls 2.12

Item{
    id: root
    signal removeMe()
    signal editMe()

    height: descriptionTextField.height + innerSpace.anchors.margins
    Rectangle {
        anchors.fill: parent
        anchors.rightMargin: rightToolBarPanel.width + innerSpace.anchors.margins
        border.width: 2
        border.color: "Gold"
        color: completed ? "lightGray" : background
        Row{
            spacing: innerSpace.anchors.margins
            anchors.fill: parent
            anchors.rightMargin: innerSpace.anchors.margins
            TextArea{
                id: descriptionTextField
                width: parent.width - priorityButton.width - seperator.width - (parent.children.length - 1) * parent.spacing
                background: null
                text: description
                onTextChanged: description = text
                enabled: !completed
                wrapMode: TextEdit.Wrap
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
                enabled: !completed
                height: parent.height - innerSpace.anchors.margins
                anchors.verticalCenter: parent.verticalCenter
                model: ["NONE", "LOW", "MEDIUM", "HIGH"]
                background: Rectangle {color: "#e0e0e0";}
                indicator: Item{}
                Component.onCompleted: {
                    currentIndex = priority
                    priority = Qt.binding(function() { return currentIndex })
                }

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
                onCheckStateChanged: completed = (checkState == Qt.Checked)
                Component.onCompleted: checkState = completed ? Qt.Checked : Qt.Unchecked
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
                enabled: !completed
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

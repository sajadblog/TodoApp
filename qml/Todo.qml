import QtQuick 2.12
import QtQuick.Controls 2.12
import TodoModel 1.0
Item {
    id: innerSpace
    anchors.fill: parent
    anchors.margins: 10
    Item{
        id: newTaskPanel
        width: parent.width
        height: newTaskTextField.height
        TextField{
            id : newTaskTextField
            width: parent.width - submitButton.width - innerSpace.anchors.margins
            placeholderText : qsTr("New Task Here!")
            background: Rectangle { border.color: "blue"; border.width: 2;}
        }
        Button{
            id:submitButton
            anchors.right: parent.right
            text: qsTr("submit")
            background: Rectangle {color: "#e0e0e0"; radius: 5;}
            onClicked: {
                todoModel.addItem(newTaskTextField.text)
                newTaskTextField.text = ""
            }
        }
    }

    ListView{
        anchors{
            fill: parent
            topMargin: newTaskPanel.height + innerSpace.anchors.margins
        }
        spacing : innerSpace.anchors.margins
        model: TodoModel{ id: todoModel}
        clip: true
        delegate: TodoItem{
            width: parent.width
            onRemoveMe: todoModel.removeItem(index)
            onEditMe: colorSelector.currentRow = index
        }
    }

    ColorSelector{
        id: colorSelector
        anchors.centerIn: parent
        onColorSelected: {
            todoModel.updateBackground(currentRow, newColor )
            currentRow = -1
        }
    }
}

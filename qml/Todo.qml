import QtQuick 2.12
import QtQuick.Controls 2.12
import FilterTodoModel 1.0
import QtQuick.Dialogs 1.2

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
                filterTodoModel.model.addItem(newTaskTextField.text)
                newTaskTextField.text = ""
            }
        }
    }
    TextField{
        id : filterTextField
        width: parent.width
        anchors.top: newTaskPanel.bottom
        anchors.topMargin: innerSpace.anchors.margins
        placeholderText : qsTr("Filters")
        background: Rectangle { border.color: "blue"; border.width: 2;}
        onTextChanged: filterTodoModel.setFilters(text)
    }

    ListView{
        anchors{
            fill: parent
            topMargin: newTaskPanel.height + filterTextField.height + 2 * innerSpace.anchors.margins
            bottomMargin: saveButton.height + innerSpace.anchors.margins
        }
        spacing : innerSpace.anchors.margins
        model: FilterTodoModel{ id: filterTodoModel}
        clip: true
        delegate: TodoItem{
            width: parent.width
            onRemoveMe: filterTodoModel.model.removeItem(index)
            onEditMe: colorSelector.currentRow = index
        }
    }
    Button{
        id:saveButton
        width: parent.width
        anchors.bottom: parent.bottom
        text: qsTr("Save")
        background: Rectangle {color: "#e0e0e0"; radius: 5;}
        onClicked: filterTodoModel.saveToFile()
    }

    ColorSelector{
        id: colorSelector
        anchors.centerIn: parent
        onColorSelected: {
            filterTodoModel.model.updateBackground(currentRow, newColor )
            currentRow = -1
        }
    }
}

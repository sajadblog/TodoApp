import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Rectangle{
    id: root
    signal colorSelected(string newColor)
    property int currentRow: -1

    height: selectionLayout.height + bannerRectangle.height + resetButton.height
    width: 200
    border.width: 2
    border.color: "black"
    color: "#a9a9a9"
    visible: currentRow !== -1
    Column{
        anchors.fill: parent
        Rectangle{
            id: bannerRectangle
            width: parent.width
            height: banner.height * 2
            Text {
                id: banner
                text: qsTr("Pick Color!")
                anchors.verticalCenter: parent.verticalCenter
                x: innerSpace.anchors.margins
            }
        }

        RowLayout{
            id: selectionLayout
            height: 50
            width: parent.width
            Repeater{
                model :["red", "yellow", "#90ee90"]
                delegate: Rectangle{
                    color: modelData
                    width: 30
                    height: width
                    MouseArea{
                        anchors.fill: parent
                        onClicked: root.colorSelected(modelData)
                    }
                }
            }
        }
        Button{
            id: resetButton
            text: qsTr("Reset")
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: root.colorSelected("white")
        }
    }
}

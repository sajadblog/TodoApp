import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: root
    width: 500
    height: 450
    visible: true

    Todo{
        id: todo
        anchors.fill: parent
    }
}

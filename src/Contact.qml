import QtQuick 2.0

Row {

    spacing: 16

    property var contact: null

    Rectangle {
        anchors.verticalCenter: parent.verticalCenter
        width: 48
        height: 48
        color: "gray"
    }

    Column {
        anchors.verticalCenter: parent.verticalCenter
        spacing: 4
        Text {
            text: contact.name;
            font.pixelSize: 15
            font.bold: true
        }
        Text {
            text: "Número: +52 " + contact.phone;
            font.pixelSize: 13
        }
    }
}

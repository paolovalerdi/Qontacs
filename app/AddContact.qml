import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.12

Column {
    anchors.fill: parent
    anchors.topMargin: 72
    anchors.leftMargin: 20
    anchors.rightMargin: 20

    TextField {
        anchors.left: parent.left
        anchors.right: parent.right
        id: name
    }

    TextField {
        anchors.left: parent.left
        anchors.right: parent.right
        id: lastName
    }

    TextField {
        anchors.left: parent.left
        anchors.right: parent.right
        id: phone
    }

    Button {
        anchors.left: parent.left
        anchors.right: parent.right

        onClicked: {
            if (name.text != "" && lastName.text != "" && phone.text != "") {
                contactsController.insert(name.text, lastName.text, phone.text);
                name.text = "";
                lastName.text = "";
                phone.text = "";
                stackView.pop();
            }
        }
    }
}

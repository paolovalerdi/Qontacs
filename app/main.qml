import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.12

ApplicationWindow {
    id: root

    width: 414
    minimumWidth: 414
    maximumWidth: 414

    minimumHeight: 736
    maximumHeight: 736
    height: 736

    visible: true
    title: "Qontacts"

    AddContactScreen {
        id: addContactScreen
        anchors.fill: parent
        visible: false
        onSubmit: {
            addContactScreen.visible = false;
            contactListScreen.visible = true;
            stackView.pop();
        }
        onBackPressed: {
            addContactScreen.visible = false;
            contactListScreen.visible = true;
            stackView.pop();
        }
    }

    ContactListScreen {
        id: contactListScreen
        anchors.fill: parent
        visible: true
        onAddClicked: {
            contactListScreen.visible = false;
            addContactScreen.visible = true;
            stackView.push(addContactScreen);
        }
    }


    StackView {
        id: stackView
        anchors.fill: parent

        initialItem: contactListScreen
    }
}

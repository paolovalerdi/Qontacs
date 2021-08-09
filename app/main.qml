import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.12

ApplicationWindow {
    id: root

    width: 414
    height: 736
    visible: true
    title: "Qontacts"


    Component.onCompleted: {
        contactsController.update();
    }

    ListModel {
        id: contactsModel
    }

    Connections {
        target: contactsController

        function onStateChange(state) {
            contactsModel.clear();
            const contacts = JSON.parse(state);
            for (let i = 0; i <= contacts.length; i++) {
                contactsModel.append(contacts[i]);
            }
        }
    }


    header: ToolBar {

        Material.primary: "blue";
        Text {
            anchors.centerIn: parent
            text: "Contactos"
            color: "white"
            font.pixelSize: 20
            font.bold: true
        }
    }

    AddContact {
        anchors.fill: parent
        id: addContact
    }

    StackView {
        id: stackView
        anchors.fill: parent

        initialItem:  Rectangle {
            anchors.fill: parent
            color: "white"

            ListView {
                id: listView
                anchors.fill: parent
                anchors.margins: 16

                spacing: 8
                model: contactsModel
                delegate: Contact {
                    contact: model
                }

                RoundButton{
                    width:76
                    height: 76
                    icon.source: "add_black_24dp.svg"
                    icon.width: 40
                    icon.height: 40
                    Material.background: "blue"
                    Material.foreground: "white"
                    anchors {
                        bottom: listView.bottom
                        right: listView.right
                        bottomMargin: 10
                        rightMargin: 10
                    }
                    onClicked: stackView.push(addContact)
                }
            }
        }
    }
}

import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.12

Item {
    id: root
    signal submit()
    signal backPressed()

    ToolBar {
        id: toolbar

        anchors.top: root.top
        anchors.left: root.left
        anchors.right: root.right

        Material.primary: "#2B73D6";

        ToolButton {
            anchors.left: parent
            anchors.verticalCenter: parent.verticalCenter
            icon.source: "qrc:/arrow_back.svg"
            Material.foreground: "white"
            onClicked: { backPressed(); }
        }

        Text {
            anchors.centerIn: parent
            text: "Añadir contacto"
            color: "white"
            font.pixelSize: 18
        }
    }

    Rectangle {
        id: formContainer
        color: "transparent"
        anchors.left: root.left
        anchors.leftMargin: 20
        anchors.top: toolbar.bottom
        anchors.topMargin: 20
        anchors.right: root.right
        anchors.rightMargin: 20
        anchors.bottom: root.bottom

        Column {
            id: form
            spacing: 16
            width: formContainer.width
            height: formContainer.height

            TextField {
                id: nameTF
                width: parent.width
                placeholderText: "Nombre"
            }

            TextField {
                id: lastNameTF
                width: parent.width
                placeholderText: "Correo"
            }

            TextField {
                id: phoneTF
                width: parent.width
                placeholderText: "Número de telefono"
            }

            Button {
                width: parent.width
                text: "Agregar"
                enabled: form.isNotEmpty(nameTF.text) && form.isNotEmpty(lastNameTF.text) && form.isNotEmpty(phoneTF.text)
                onClicked: {
                    contactsController.insert(nameTF.text, lastNameTF.text, phoneTF.text);
                    form.resetTextFields();
                    root.submit();
                }
            }

            function resetTextFields() {
                nameTF.text = "";
                lastNameTF.text = "";
                phoneTF.text = "";
            }

            function isNotEmpty(value) {
                return value.length > 0;
            }
        }
    }
}

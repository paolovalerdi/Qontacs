#include "contacts_controller.h"


ContactsController::ContactsController(ContactsManager manager, QObject *parent) : QObject(parent), manager(manager)
{
}

void ContactsController::update()
{
    auto contacts = QJsonArray();
    for (auto contact : manager.contacts()) {
        contacts.append(contact.toJson());
    }
    QJsonDocument document;
    document.setArray(contacts);
    emit stateChange(document.toJson());
}

void ContactsController::insert(QString name, QString email, QString phone)
{
    manager.insert(Contact(name, email, phone));
    update();
}

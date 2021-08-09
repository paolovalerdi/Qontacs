#include "contacts_controller.h"


ContactsController::ContactsController(ContactsManager manager, QObject *parent) : QObject(parent), manager(manager)
{
}

void ContactsController::update()
{
    QString state = "[";
    auto contacts = QStringList();
    for (auto contact : manager.contacts()) {
        contacts.append(contact.toJson());
    }
    state = state += contacts.join(",");
    state = state += "]";

    emit stateChange(state);
}

void ContactsController::insert(QString name, QString lastName, QString phone)
{
    manager.insert(Contact(name, lastName, phone));
    update();
}

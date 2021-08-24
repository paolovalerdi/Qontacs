#include "contacts_manager.h"

ContactsManager::ContactsManager(QSqlDatabase db)
{
    this->db = db;
}

QList<Contact> ContactsManager::contacts()
{
    auto contacts = QList<Contact>();
    auto query = QSqlQuery(db);
    if (query.exec("SELECT * FROM contacts ORDER BY name ASC")) {
        while(query.next()) {
            auto contact = Contact::fromSqlQuery(query);
            contacts.append(contact);
        }
    } else {
        qDebug() << "ContactsManager::contacts() failed with error: "
                 << query.lastError().text();
    }
    return contacts;
}

void ContactsManager::insert(Contact contact)
{
    QSqlQuery query;
    auto command = QString(
                "INSERT INTO contacts (name, email, phone) "
                "VALUES ('%1', '%2', '%3')"
            ).arg(contact.name())
            .arg(contact.email())
            .arg(contact.phone());
    if (!query.exec(command)) {
        qDebug() << query.lastError();
    }
}

void ContactsManager::update(Contact contact)
{
    // TODO: Implement
}

void ContactsManager::remove(Contact contact)
{
    // TODO: Implement
}

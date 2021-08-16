#include "contacts_manager.h"

ContactsManager::ContactsManager(QSqlDatabase db)
{
    this->db = db;
}

void ContactsManager::insert(Contact contact)
{
    QSqlQuery query;
    auto command = QString("INSERT INTO contacts VALUES('%1', '%2', '%3')")
            .arg(contact.name())
            .arg(contact.lastName())
            .arg(contact.phone());
//    query.prepare();

//    query.bindValue(":name", contact.name());
//    query.bindValue(":last_name", contact.lastName());
//    query.bindValue(":phone", contact.phone());
    if (!query.exec(command)) {
        qDebug() << query.lastError();
    }
}

QList<Contact> ContactsManager::contacts()
{
    auto contacts = QList<Contact>();
    QSqlQuery query;
    query.prepare("SELECT * FROM contacts");

   if (query.exec()) {
        while(query.next()) {
            auto contact = Contact(query.value("name").toString(),
                                   query.value("last_name").toString(),
                                   query.value("phone").toString());
            contacts.append(contact);
        }
    } else {
        qDebug() << "ContactsManager::contacts() failed with error: "
                 << query.lastError().text();
    }
    return contacts;
}

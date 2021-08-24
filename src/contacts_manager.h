#pragma once

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include "contact.h"

class ContactsManager
{
private:
    QSqlDatabase db;
public:
    ContactsManager(QSqlDatabase db);
    QList<Contact> contacts();
    void insert(Contact contact);
    void update(Contact contact);
    void remove(Contact contact);
};

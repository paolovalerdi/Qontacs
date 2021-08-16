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
    void insert(Contact contact);
    QList<Contact> contacts();
};

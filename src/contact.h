#pragma once

#include <QString>
#include <QSqlQuery>
#include <QJsonObject>

class Contact
{
public:
    static Contact fromSqlQuery(QSqlQuery query);

    Contact(QString name, QString email, QString phone);
    Contact(int id, QString name, QString email, QString phone);

    const int &id() const;
    const QString &name() const;
    const QString &email() const;
    const QString &phone() const;

    QJsonObject toJson();
    Contact copy(int* id = nullptr,
                 QString* name = nullptr,
                 QString* email = nullptr,
                 QString* phone = nullptr);
private:
    int _id;
    QString _name;
    QString _email;
    QString _phone;
};

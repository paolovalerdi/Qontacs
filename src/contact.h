#pragma once

#include <QString>

class Contact
{
public:
    Contact(QString name, QString lastName, QString phone);
    const QString &name() const;
    const QString &lastName() const;
    const QString &phone() const;
    QString toJson();
private:
    QString _name;
    QString _lastName;
    QString _phone;
};

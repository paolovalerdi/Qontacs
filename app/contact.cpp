#include "contact.h"

Contact::Contact(QString name, QString lastName, QString phone)
    : _name(name),
      _lastName(lastName),
      _phone(phone) {
}

const QString &Contact::name() const
{
    return _name;
}

const QString &Contact::lastName() const
{
    return _lastName;
}

const QString &Contact::phone() const
{
    return _phone;
}

QString Contact::toJson()
{
    auto name = QString("%1 %2").arg(_name).arg(_lastName);
    return QString("{\"name\": \"%1\", \"phone\": \"%2\"}").arg(name, _phone);
}

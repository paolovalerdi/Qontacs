#include "contact.h"

Contact Contact::fromSqlQuery(QSqlQuery query)
{
    auto id = query.value("id").toInt();
    auto name = query.value("name").toString();
    auto email = query.value("email").toString();
    auto phone = query.value("phone").toString();
    return Contact(id, name, email, phone);
}

Contact::Contact(QString name, QString lastName, QString phone)
    :_id(-1),
      _name(name),
      _email(lastName),
      _phone(phone) {
}

Contact::Contact(int id, QString name, QString lastName, QString phone)
    : _id(id),
      _name(name),
      _email(lastName),
      _phone(phone) {
}

const int &Contact::id() const
{
    return _id;
}

const QString &Contact::name() const
{
    return _name;
}

const QString &Contact::email() const
{
    return _email;
}

const QString &Contact::phone() const
{
    return _phone;
}

bool Contact::operator==(const Contact &other) const
{
    return this->_id == other._id &&
            this->_name == other._name &&
            this->_email == other._email &&
            this->_phone == other._phone;
}

QJsonObject Contact::toJson()
{
    QJsonObject json {
        {"id", _id},
        {"name", _name},
        {"email", _email},
        {"phone", _phone},
    };
    return json;
}

Contact Contact::copy(int *id, QString *name, QString *email, QString *phone)
{
    return Contact(id != nullptr ? *id : _id,
                   name != nullptr ? *name : _name,
                   email != nullptr ? *email : _email,
                   phone != nullptr ? *phone : _phone);
}

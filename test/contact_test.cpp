#include <QtTest>
#include <QJsonObject>

#include "contact.h"

class ContactTest : public QObject
{
    Q_OBJECT

public:
    ContactTest();
    ~ContactTest();

private slots:
    void toJsonReturnsAProperJsonObject();
};

ContactTest::ContactTest()
{

}

ContactTest::~ContactTest()
{

}

void ContactTest::toJsonReturnsAProperJsonObject()
{
    auto paolo = Contact(1, "Paolo", "me@gmail.com", "1234567890");
    QJsonObject expected {
        {"id", 1},
        {"name", "Paolo"},
        {"email", "me@gmail.com"},
        {"phone", "1234567890"},
    };

    QCOMPARE(paolo.toJson(), expected);
}

//QTEST_APPLESS_MAIN(ContactTest)

#include "contact_test.moc"

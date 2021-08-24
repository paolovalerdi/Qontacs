#include <QtTest>
#include <QSqlDatabase>

#include "contact.h"
#include "contacts_manager.h"

class ContactsManagerTest : public QObject
{
    Q_OBJECT
public:
    ContactsManagerTest() {}
    ~ContactsManagerTest() {}

private:
    QSqlDatabase fakeDatabase;
private slots:
    void init() {
        // Set up an in-memory db every time a test-function is invoked
        fakeDatabase = QSqlDatabase::addDatabase("QSQLITE");
        fakeDatabase.setDatabaseName(":memory:");
        fakeDatabase.open();
        fakeDatabase.exec("CREATE TABLE IF NOT EXISTS contacts ("
               "id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
               "name TEXT NOT NULL, "
               "email TEXT NOT NULL, "
               "phone TEXT NOT NULL"
               ");");
    }
    void cleanup() {
        // Close the last in-memory db
        fakeDatabase.close();
    }
    void everyInsertedContactIsReturned() {
        auto manager = ContactsManager(fakeDatabase);
        auto expectedList = QList<Contact>();
        expectedList.append(Contact(1, "Baz", "baz@gmai.com", "54321"));
        expectedList.append(Contact(2, "Foo", "foo@gmai.com", "12345"));

        for (const auto &contact : expectedList) {
            manager.insert(contact);
        }

        auto stored = manager.contacts();

        // Both list should contain the exact same values
        // so both should be the same length
        for (int i = 0; i < expectedList.length(); i++) {
            auto dbOne = stored.at(i);
            auto expectedOne = expectedList.at(i);
            QCOMPARE(dbOne, expectedOne);
        }
    }
};

#include "contacts_manager_test.moc"

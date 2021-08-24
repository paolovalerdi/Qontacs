#include <QtTest>

#include "contact_test.cpp"
#include "contacts_manager_test.cpp"

// TODO: This is quite ugly
// The way this works is that we run the qExect fuction
// for each "test" class there may be.
// This will not scale at all, but what can I say? Qt being Qt ¯\_(ツ)_/¯
int main(int argc, char *argv[])
{
    ContactTest contactTest;
    ContactsManagerTest contactsManagerTest;
    return QTest::qExec(&contactTest, argc, argv) ||
            QTest::qExec(&contactsManagerTest, argc, argv);
}

#include <QtTest>

// add necessary includes here

class foo : public QObject
{
    Q_OBJECT

public:
    foo();
    ~foo();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

foo::foo()
{

}

foo::~foo()
{

}

void foo::initTestCase()
{

}

void foo::cleanupTestCase()
{


}

void foo::test_case1()
{

}

QTEST_APPLESS_MAIN(foo)

#include "tst_foo.moc"

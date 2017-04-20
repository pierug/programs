#include <QString>
#include <QtTest>
#include "../database.h"
class TestTest : public QObject
{
    Q_OBJECT

public:
    TestTest();
    Database* database;
private Q_SLOTS:
    void testCase1();
};

TestTest::TestTest()
{
    database=new Database;
    QVERIFY2(database!=NULL,"Created Database object");
}

void TestTest::testCase1()
{

    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TestTest)

#include "tst_testtest.moc"

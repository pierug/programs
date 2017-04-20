#include <QString>
#include <QtTest>
#include ""
class MySqlTestTest : public QObject
{
    Q_OBJECT

public:
    MySqlTestTest();

private Q_SLOTS:
    void testCase1();
};

MySqlTestTest::MySqlTestTest()
{
}

void MySqlTestTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(MySqlTestTest)

#include "tst_mysqltesttest.moc"

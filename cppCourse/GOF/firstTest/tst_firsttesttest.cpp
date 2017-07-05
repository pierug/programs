#include <QString>
#include <QtTest>
#include "../gangOfFour/abstractfactory.h"

class FirstTestTest : public QObject
{
    Q_OBJECT

public:
    FirstTestTest();
    AbstractFactory* abstractFactory;

    ~FirstTestTest(){
        delete abstractFactory;
    }
private Q_SLOTS:
    void testCase1();
    void createMercedesFactory();
    void isNULLAbstractFactory();
    void createMercedesCar();
};

FirstTestTest::FirstTestTest()
{

}

void FirstTestTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

void FirstTestTest::createMercedesFactory(){
    abstractFactory = new MercedesFactory();
    QVERIFY2(abstractFactory!=NULL, "Null pointer MercedesFactory");
}

void FirstTestTest::isNULLAbstractFactory()
{
    QVERIFY2(abstractFactory!=NULL, "Null pointer abstractFactory");
}

void FirstTestTest::createMercedesCar()
{
    abstractFactory=new MercedesFactory();
    Vehicle* vehicle = abstractFactory->createCar();

    QVERIFY2(vehicle->display()=="Car Mercedes","createMercedesCar()");
}

QTEST_APPLESS_MAIN(FirstTestTest)

#include "tst_firsttesttest.moc"

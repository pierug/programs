#ifndef TESTSOMETHING_H
#define TESTSOMETHING_H


#include <QtTest/QtTest>

class TestSomething : public QObject {
    Q_OBJECT

private slots:
    // functions executed by QtTest before and after test suite
    void initTestCase();
    void cleanupTestCase();

    // functions executed by QtTest before and after each test
    void init();
    void cleanup();

    // test functions - all functions prefixed with "test" will be ran as tests
    void testSomething();
};
#endif // TESTSOMETHING_H

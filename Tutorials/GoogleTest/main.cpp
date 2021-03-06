#include "mainwindow.h"
#include <QApplication>
#include "include/gtest/gtest.h"

bool IsPrime(int n)
{
    // Trivial case 1: small numbers
    if (n <= 1) return false;

    // Trivial case 2: even numbers
    if (n % 2 == 0) return n == 2;

    // Now, we have that n is odd and n >= 3.

    // Try to divide n by every odd number i, starting from 3
    for (int i = 3; ; i += 2) {
        // We only have to try i up to the squre root of n
        if (i > n/i) break;

        // Now, we have i <= n/i < n.
        // If n is divisible by i, n is not prime.
        if (n % i == 0) return false;
    }
    // n has no integer factor in the range (1, n), and thus is prime.
    return true;
}
class IsPrimeParamTest : public::testing::TestWithParam<int>
{

};
TEST_P(IsPrimeParamTest, HandleTrueReturn)
{
    int n =  GetParam();
    EXPECT_TRUE(IsPrime(n));
}
INSTANTIATE_TEST_CASE_P(TrueReturn, IsPrimeParamTest, testing::Values(3, 5, 11, 23, 17));

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();*/

    return a.exec();
}

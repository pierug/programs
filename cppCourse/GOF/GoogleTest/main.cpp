#include <QCoreApplication>
#include "gtest/gtest.h"

bool IsPrime(int n)
{
    if (n <= 1) return false;
    if (n % 2 == 0) return n == 2;
    for (int i = 3; ; i += 2) {
        if (i > n/i) break;
        if (n % i == 0) return false;
    }
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
    QCoreApplication a(argc, argv);

        testing::InitGoogleTest(&argc, argv);
        RUN_ALL_TESTS();
    return a.exec();
}

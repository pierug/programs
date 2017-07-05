#include <QCoreApplication>
#include "effort.h"
#include "fibonacci.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

/*
    Effort effort;
    effort.efforTestWithout();
    effort.efforTestWith();
*/
    Fibonacci fib(19);
    //fib.makeNormalFib();
    fib.makeReclFib();
    fib.display();
    return a.exec();
}

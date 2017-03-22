#include <QCoreApplication>
#include "effort.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    Effort effort;
    effort.efforTestWithout();
    effort.efforTestWith();

    return a.exec();
}

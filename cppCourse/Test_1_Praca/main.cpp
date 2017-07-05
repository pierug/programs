#include <QCoreApplication>
#include "singleton.h"
#include <vector>

#define FIB_ARRAY_LENGHT    10

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Singleton* s = Singleton::getInstance();
    s->disp();
    int *array;
    //array = s->makeFibonaci(FIB_ARRAY_LENGHT);
    array = s->makeRecFibonaci(0,FIB_ARRAY_LENGHT,array);
    s->dispArray(FIB_ARRAY_LENGHT,array);

    vector<string> vec;
    vec = s->splitStringTxt("Ala ma kota, I ty tez, kurczaki, pies",',');
    s->dispSplitTxt(vec);

    s->Karp_Rabin("dupa mpkra w pipe","pi");

    int array2[] = {11,4,23,1,52,1,43,22,2,32};
    //s->quicksort(array2,0,10);
    //s->insertsort(FIB_ARRAY_LENGHT,array2);
    s->selectionsort(FIB_ARRAY_LENGHT,array2);
    s->dispArray(FIB_ARRAY_LENGHT,array2);

    delete array;
    return a.exec();
}

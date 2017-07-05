#include <iostream>
#include <vector>
#include <iterator>
#include "heap.h"
using namespace std;


int main()
{
    // Create the heap
    Heap<int> myheap;
    myheap.insert(12);
    myheap.insert(1);
    myheap.insert(122);
    myheap.insert(14);
    myheap.insert(19);
    myheap.insert(16);
    myheap.insert(10);
    myheap.insert(8);
    myheap.insert(6);
    myheap.insert(15);
    myheap.insert(22);
    myheap.insert(142);
    myheap.deletemin();
    myheap.deletemin();
    myheap.deletemin();
    myheap.print();
    // Get priority eleme   nt from the heap
    /*int heapSize = myheap->size();
    for ( int i = 0; i < heapSize; i++ )
        cout << "Get min element = " << myheap->deletemin() << endl;
*/
    // Cleanup

}

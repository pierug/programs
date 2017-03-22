#include <iostream>
#include "structures.h"
#include "element.h"
#include "myStack.h"
#include "mylist.h"
#include "queue.h"
using namespace std;

int main(int argc, char *argv[])
{

    /*Stack*/
  /*  cout<<"Stack: "<<endl;
    MyStack<int> s;
    s.pushFront(14);
    s.pushFront(664);
    s.pushFront(24);
    s.pushFront(1);
    s.popFront();
    s.popFront();
    s.pushFront(66);


    MyStack<int> d(s);
    s.popFront();
    s.popFront();
    s.display();
    d.display();
    s=d;
    cout<<"s=d"<<endl;
    s.display();

*/
    /*List*/
  /*  cout<<"List: "<<endl;
    MyList<string> list1;
    list1.pushFront("cat");
    list1.pushFront("dog");
    list1.pushBack("fish");
    list1.pushFront("bird");
    list1.display();

    MyList<string> list2(list1);

    list2.pushFront("cow");
    list2.pushFront("pig");
    list2.pushBack("camel");
    list2.pushFront("rabbit");

    list2.popBack();
    list2.popBack();
    list2.display();


    list1.popFront();
    list1.popFront();
    list1.display();
    list2.display();
*/
    /*Queue*/
    Queue <int>queue;

    //queue.push(14);
    //queue.push(3);
    queue.push(55);
    queue.push(1);
    queue.push(33);
    queue.push(5);
    queue.selectionSort();
    queue.display();

    //cout<<"lenght: "<<queue.lenght()<<", getAt(3)"<<queue.getAt(3)<<endl;
    //queue.setAt(4,queue.getAt(0));

    //queue.display();

    return 0;
}

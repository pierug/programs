#include <iostream>
#include <memory>

using namespace std;


int main(int argc, char *argv[])
{
    unique_ptr<int> uPtr1(new int(13));
    shared_ptr<int> uPtr2(new int(14));
    //uPtr1=uPtr2;
    cout << *uPtr1 << endl;
    return 0;
}

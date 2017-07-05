#ifndef FACADE_H
#define FACADE_H

#include <iostream>

using namespace std;

template<typename T>

class System{
public:
    inline static void software()
    {
        return T::software();
    }
};

class Windows{
public:
    inline static void software(){
        cout<<"To Windows"<<endl;
    }
};

class Linux{
public:
    inline static void software(){
        cout<<"To Linux"<<endl;
    }
};

#if defined(__LINUX__) || defined(__linux__)
    typedef System<Linux> system;
#elif defined(__WIN32__) || defined(__WIN64__)
    typedef System<Windows> systemInterface;
#endif


#endif // FACADE_H

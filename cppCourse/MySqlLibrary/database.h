#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
//#include <sql.h>

using namespace std;

class Database
{
public:
    Database();


    virtual void makeConnection()=0;
    virtual void insertData(string values, string columns, string )=0;

};

#endif // DATABASE_H

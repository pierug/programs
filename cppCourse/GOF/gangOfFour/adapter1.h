#ifndef ADAPTER1_H
#define ADAPTER1_H

#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

class Timer{
public:
    virtual char* printTime()=0;
    virtual ~Timer(){}
};

class OSITimer{
public:
    char* printOSITime(){
        static char buf[80];
        tm *timeNow;
        time_t secsNow;
        tzset();
        time(&secsNow);
        timeNow=localtime(&secsNow);
        strftime(buf,80,"%M min po godzinie %I %A %d 20%y\n\n",timeNow);
        return buf;
    }
};

class WINTimer:public Timer, private OSITimer{
public:
    char* printTime(){
        static char buf[80];
        char *ptr, nt[80];
        cout<<"Zegar WIN nie działa"<<endl;
        ptr= OSITimer::printOSITime();

        strcpy(nt,&ptr[0]);
        sprintf(buf,"%s",nt);
        return buf;
    }
};

#endif // ADAPTER1_H

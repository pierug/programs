#ifndef CEOCOMPOSITE_H
#define CEOCOMPOSITE_H
#include <iostream>
#include <vector>

using namespace std;


class CEOComponent{

public:
    CEOComponent(string name, double salary)
        :m_fullName(name) , m_valueSalary(salary){}

    virtual void printSalary(int level)=0;
    string m_fullName;
    double m_valueSalary;
};


class Worker: public CEOComponent{
public:
    Worker(string name, double salary):CEOComponent(name,salary){}
    void printSalary(int level){
        for(int j=0;j<level;j++)
            cout<<"\t";
        cout<<"Worker: "<<m_fullName<<", salary: "<<m_valueSalary<<"$"<<endl;
    }
};

class Manager:public CEOComponent{
private:
    vector <CEOComponent*> m_children;
public:
    Manager(string name, double salary):CEOComponent(name,salary){}
    void printSalary(int level){
        for(int j=0;j<level;j++)
            cout<<"\t";
        cout<<"Manager: "<<m_fullName<<", salary: "<<m_valueSalary<<"$"<<endl;
        if(!m_children.empty()){
            for (int i = 0; i < level; ++i)cout<<"\t";
            cout<<"Subordinates of "<<m_fullName<<":"<<endl;
            level++;
            for (int i = 0; i < m_children.size(); ++i)
                m_children[i]->printSalary(level);
        }
    }
    void add(CEOComponent* c){
        m_children.push_back(c);
    }
};

#endif // CEOCOMPOSITE_H

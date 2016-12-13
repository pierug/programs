#include <iostream>

using namespace std;


struct Lista{

    struct Student{
        int index;
        double oceny[4];
        struct Student *next;
        struct Student *previous;
        Student(){
            previous=NULL;
            next=NULL;
        }
    };

    Lista(){
        wsk=NULL;
        beg=NULL;
    }
    Student *wsk;
    Student *beg;

    void push(int ID, double oce[])
    {
        struct Student *newStudent = new Student;
        newStudent->index=ID;
        int i;
        for(i=0;i<4;i++)
            newStudent->oceny[i]=oce[i];
        if (this->wsk==NULL)
        {
            this->beg=newStudent;
            this->wsk=newStudent;
        }else
        {
            this->wsk->next=newStudent;
            newStudent->previous=this->wsk;
            this->wsk=newStudent;
        }
    }
    void print(void){
        struct Student *tmp=this->beg;
        while(tmp!=NULL)
        {
            cout<<tmp->index<<endl;
            tmp=tmp->next;
        }
    }
    void sort_sort(struct Student *tab5,struct Student *tab3)
    {

    }

};

int main()
{
    Lista l;
    double g1[] = {5,5,5,5};
    double g2[] = {3,3,3,3};
    double g3[] = {2,3,3,2};
    double g4[] = {5,5,5,4};
    double g5[] = {5,5,5,3};


    l.push(1,g1);
    l.push(2,g2);
    l.push(3,g3);
    l.push(4,g4);
    l.push(5,g5);


    l.print();
    return 0;
}

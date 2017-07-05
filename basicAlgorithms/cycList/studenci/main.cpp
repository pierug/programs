#include <iostream>
#include<vector>
using namespace std;
using namespace std;

struct List{

    struct Student{
        int NoID;
        int index;
        double grad[3];
        double sum;
        int numbers5;
        struct Student *previous;
        struct Student *next;
        Student(){
            numbers5 = 0;
            NoID = 0;
            sum=0;
            previous = NULL;
            next = NULL;
        }
    };
    List(){
        fron=NULL;
        bac=NULL;
    }

    Student *fron;
    Student *bac;

    void add_fornt_student(double grate[], int ID, int inde)
    {
        Student *newStudent = new Student();
        newStudent->NoID = ID;
        newStudent->index = inde;
        for(int i = 0;i<3;i++)
            newStudent->grad[i] = grate[i];
        if(this->bac==NULL)
        {
            this->fron = newStudent;
            this->fron->previous = this->bac;
            this->bac = newStudent;
            this->bac->next = this->fron;
        }
        else
        {
            this->fron->next = newStudent;
            newStudent->previous = this->fron;
            this->fron = newStudent;
        }
    }
    void add_back_student(double grate[], int ID)
    {
        Student *newStudent = new Student();
        newStudent->NoID = ID;
        for(int i = 0;i<3;i++)
            newStudent->grad[i] = grate[i];
        if(this->bac==NULL)
        {
            this->fron = newStudent;
            this->fron->previous = this->bac;
            this->bac = newStudent;
            this->bac->next = this->fron;
        }
        else
        {
            this->bac->previous = newStudent;
            newStudent->next = this->bac;
            this->bac = newStudent;
        }
    }
    void print_list(void)
    {
        Student *tmp = this->bac;
        while(tmp!=NULL)
        {
            cout<<" ID: "<<tmp->NoID<<" oceny: "<<tmp->grad[0]<<" : "<<tmp->grad[1]<<" : "<<tmp->grad[2]<<"  suma: "<<tmp->sum<<" liczba piatek: "<<tmp->numbers5<<endl;
            tmp=tmp->next;
        }
    }

    void insertsort_add_student(struct Student *S, /*double grate[], int ID,*/ int inde){

        Student *newStudent = S;
        int i=0;
        if(newStudent->numbers5)
        {
            if(this->bac==NULL)
            {
                this->fron = newStudent;
                this->fron->previous = this->bac;
                this->bac = newStudent;
                this->bac->next = this->fron;

            }
            else
            {
                this->fron->next = newStudent;
                newStudent->previous = this->fron;
                this->fron = newStudent;

/*
                if(newStudent->numbers5==1){
                    this->bac->previous = newStudent;
                    newStudent->next = this->bac;
                    this->bac = newStudent;
                }
               else if(newStudent->numbers5==2){
                    Student *tmp=this->bac;
                    for(i=0;i<inde;i++){
                        if(tmp->numbers5==2){
                            tmp->previous->next = newStudent;
                            tmp->previous = newStudent;
                            newStudent->previous = tmp->previous;
                            newStudent->next = tmp;
                            break;
                        }
                        tmp=tmp->next;
                    }
                    if (tmp->numbers5!=2){
                        this->fron->next = newStudent;
                        newStudent->previous = this->fron;
                        this->fron = newStudent;
                    }
                }
                else{
                    this->fron->next = newStudent;
                    newStudent->previous = this->fron;
                    this->fron = newStudent;
                }*/

            }
        }
    }/*
    void insertsort(struct List *l1, int n)
    {

        int i,j,k,tmp;

        for(i=1;i<n;i++)
        {
            j=i-1;

            tmp=T[i];
            while(j>=0 && T[j]>tmp)
            {
                T[j+1]=T[j];
                j--;
            }
            T[j+1]=tmp;
        }
    }*/

    void binary_sort(struct List *l1,struct List *l2)
    {
        Student *tmp = this->bac;

        int no5 = 0;
        int no35 = 0;
        for(int j=0;j<10;j++)
        {
            cout<<"________________________________"<<endl;
            for(int i = 0; i<3;i++){
                tmp->sum = tmp->sum + tmp->grad[i];
                if (tmp->grad[i]==5)
                    tmp->numbers5++;
            }
            if(tmp->numbers5)
            {
                no5++;
                l1->insertsort_add_student(tmp,no5);
                //l1->add_fornt_student(tmp->grad, tmp->NoID, no5);
            }
            else if((tmp->sum/3)<=3.5)
            {
                no35++;
                l2->insertsort_add_student(tmp,no35);
                //l2->add_fornt_student(tmp->grad, tmp->NoID, no35);
            }
            tmp=tmp->next;
        }

    }
};

int main()
{
    List l;
    List l11;
    List l22;
    double g1[] = {5,5,5};
    double g2[] = {3,3,3};
    double g3[] = {2,3,3};
    double g4[] = {5,5,5};
    double g5[] = {5,5,3};
    double g6[] = {2,5,5};
    double g7[] = {3,3,2};
    double g8[] = {2,3,3};
    double g9[] = {3,3.5,4};
    double g0[] = {5,2,4};

    l.add_fornt_student(g1,1,1);
    l.add_fornt_student(g2,2,2);
    l.add_fornt_student(g3,3,3);
    l.add_fornt_student(g4,4,4);
    l.add_fornt_student(g5,5,5);
    l.add_fornt_student(g6,6,6);
    l.add_fornt_student(g7,7,7);
    l.add_fornt_student(g8,8,8);
    l.add_fornt_student(g9,9,9);
    l.add_fornt_student(g0,10,10);

    l.print_list();

    cout<<"________________________________"<<endl;

    l.binary_sort(&l11,&l22);
    l.print_list();
    cout<<"________________________________"<<endl;
    cout<<"____________L1__________________"<<endl;
    l11.print_list();
    cout<<"________________________________"<<endl;
    cout<<"____________L2__________________"<<endl;
    l22.print_list();
    return 0;
}


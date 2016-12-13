#include <iostream>

using namespace std;

template <typename T>

struct List{
    struct ListElement{
        struct ListElement* next;
        struct ListElement* previous;
        T num;
    };

    List(){
        fron = NULL;
        bac = NULL;
        list_size = 0;
    }
    ListElement *fron;
    ListElement *bac;
    unsigned int list_size;

    void Push_Back(T t){

        ListElement* newElem = new ListElement();
        newElem->num = t;

        if(this->bac==NULL)
        {
            newElem->next=NULL;
            newElem->previous=NULL;
            this->bac = newElem;
            this->fron = this->bac;

        }
        else
        {
            newElem->next = NULL;
            newElem->previous = this->bac;
            this->bac->next = newElem;
            this->bac = newElem;
        }

    }

    void Push_Front(T t){

        ListElement* newElem = new ListElement();
        newElem->num = t;

        if(this->fron==NULL)
        {
            newElem->next = NULL;
            newElem->previous = NULL;
            this->fron = newElem;
            this->bac = this->fron;
        }
        else
        {
            newElem->next = this->fron;
            newElem->previous = NULL;
            this->fron->previous = newElem;
            this->fron = newElem;
        }
    }

    T Pop_Back(void){
        T value;
        if (this->bac == NULL)
        {
            cout << "Pusta lista" << endl;
            return T();
        }
        else
        {
            value = this->bac->num;
            ListElement* oldBack = this->bac;

            this->bac = oldBack->previous;
            delete oldBack;
            this->bac->next = NULL;
            if(this->bac == NULL)
            {
                this->fron=NULL;
            }
        }
        return value;
    }

    T Pop_Front(void){
        T value;
        if (this->fron == NULL)
        {
            cout << "Pusta lista" << endl;
            return T();
        }
        else
        {
            value = this->fron->num;
            ListElement* oldFront = this->fron;

            this->fron = oldFront->next;

            delete oldFront;
            this->fron->previous = NULL;
            if(this->fron == NULL)
            {
                this->bac=NULL;
            }
        }
        return value;
    }

    void Print_List(){
        ListElement* e = this->fron;
        while (e!=NULL) {
            cout << e->num << endl;
            e = e->next;
        }
    }
};

int main()
{
    int s;
    List<int> l;

    l.Push_Back(2);

    l.Push_Back(5);

    l.Push_Back(1);

    l.Push_Front(14);

    l.Push_Back(2);

    l.Push_Front(25);
    s = l.Pop_Back();
    s = l.Pop_Front();
    s = l.Pop_Front();
    s = l.Pop_Front();

    l.Print_List();
    //cout<<s;
    return 0;
}

#include <iostream>

using namespace std;

template <typename T>

struct FIFO
{
    struct FIFOelement{

        struct FIFOelement* next;
        T num;
    };

    FIFO()
    {
        head=NULL;
        tail=NULL;
    }

    FIFOelement* head;
    FIFOelement* tail;

    void Equeue_sort(T t){
        FIFOelement* newElem = new FIFOelement();
        newElem->num = t;
        if (this->head==NULL){
            this->head = newElem;
            this->head->next=NULL;
        }else{
            FIFOelement* tmp = this->head;
            FIFOelement* previoius = tmp;
            if(this->tail==NULL){
                if(tmp->num<newElem->num){
                    this->head->next = newElem;
                    this->tail = newElem;
                }else{
                    this->tail = this->head;
                    this->head = newElem;
                    this->head->next=this->tail;
                }
            }else{
                while(tmp->num<newElem->num && tmp->next!=this->tail){
                    previoius = tmp;
                    tmp=tmp->next;
                }
                if(tmp->num>newElem->num){
                    newElem->next=tmp;
                    previoius->next=newElem;
                }
            }
            this->tail->next=NULL;
        }
    }
    void Equeue(T t)
    {
        FIFOelement* newElem = new FIFOelement();
        newElem->num = t;
        if (this->head==NULL)
        {
            this->head = newElem;
        }
        else
        {
            if (this->tail==NULL)
            {
                this->head->next = newElem;
            }
            else
            {
                this->tail->next = newElem;
            }
            this->tail = newElem;
        }
    }
    T Dequeue()
    {
        T value;
        if (this->head!=NULL)
        {
            value = this->head->num;
            FIFOelement* oldHead= this->head;

            this->head = this->head->next;
            delete oldHead;
            if(this->head == NULL)
            {
                this->tail=NULL;
            }
        }
        else
        {
            cout << "kolejka jest pusta" << endl;
            return T();
        }
        return value;
    }

    void Print_FIFO()
    {
        FIFOelement* e = this->head;
        while (e!=NULL) {
            cout <<"  "<< e->num;
            e = e->next;
        }
        cout <<"  "<< endl;
    }
    void suma_zbiorow(FIFOelement p1, FIFOelement k1, FIFOelement p2, FIFOelement k2, FIFOelement *ps, FIFOelement *ks){
        FIFOelement tmp1 = p1;
        FIFOelement tmp2 = p2;
        int i=0,j=0;
        while(tmp1!=k1)
        {
            i++;
            tmp1 = tmp1->next;
        }
        while(tmp2!=k2)
        {
            j++;
            tmp2 = tmp2->next;
        }
        ps = p1;
        FIFOelement S = ps;
        tmp2 = p2;
        FIFOelement previous = new FIFOelement();
        while(tmp2!=k2){
            if(tmp2->num > S->num)
            {
                if(tmp2->num < S->next->num)
                {
                    tmp2->next = S->next;
                    S->next = tmp2;
                    previous = S;
                    S = tmp2;
                }
            }
            tmp2 = tmp2->next;
        }
    }
};

int main()
{
    FIFO<int> pierwsza;
    FIFO<int> druga;
    FIFO<int> suma;

    pierwsza.Equeue(1);
    pierwsza.Equeue(5);
    pierwsza.Equeue(9);

    druga.Equeue(2);
    druga.Equeue(6);
    druga.Equeue(8);

    suma.suma_zbiorow(pierwsza->tail, pierwsza.head, druga.tail, druga.head, &suma.tail, &suma.head);
    pierwsza.Print_FIFO();
    druga.Print_FIFO();
    return 0;
}





















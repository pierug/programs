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
        while (e) {
            cout << e->num << endl;
            e = e->next;
        }
    }

};

int main()
{
    FIFO<int> s;
    s.Equeue(13);
    s.Equeue(4);
    s.Equeue(1);
    s.Equeue(3);

    s.Dequeue();
    s.Dequeue();
    s.Dequeue();
    s.Dequeue();
    s.Equeue(5);

    s.Equeue(45);
    s.Equeue(24);
    s.Dequeue();

    s.Print_FIFO();
   /* s.Equeue(7);
    cout<<s.Dequeue()<<endl;
    s.Equeue(13);
    cout<<s.Dequeue()<<endl;
    cout<<s.Dequeue()<<endl;*/
    return 0;
}

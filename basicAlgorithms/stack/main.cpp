#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

template <typename T>
struct Stack
{
    struct StackElement
    {
        struct StackElement* next;
        T num;
    };

    Stack()
    {
        top = NULL;
    }
    StackElement* top;

    void Push(T t)
    {
        StackElement* newElem = new StackElement();
        newElem->num = t;
        StackElement* oldTop = this->top;
        this->top = newElem;
        newElem->next = oldTop;
    }

    T Pop()
    {
        if (this->top == NULL)
        {
            cout << "Stos pusty" << endl;
            return T();
        }
        StackElement* oldTop = this->top;
        this->top = oldTop->next;
        T value = oldTop->num;
        delete oldTop;
        return value;
    }

    void Print_Top()
    {
        if(this->top==NULL)
        {
            cout<<"stos jest pusty"<<endl;
        }
        else
        {
            cout<<this->top<<endl;
        }
    }

    void Print_Sack()
    {
        StackElement* e = this->top;
        while (e) {
            cout << e->num << endl;
            e = e->next;
        }
    }
};


int main()
{
    Stack<string> s;
    s.Push("World");
    s.Push(" ");
    s.Pop();
    s.Push("Hello");
    s.Print_Sack();
    return 0;
}
/*
struct Stack
{
    int *stos;
    int top;

};
void Stack_init(struct Stack *S)
{
    S->stos = new int;
    S->top=0;
}

void Push(struct Stack *S,int t)
{
    S->top++;
    S->stos[S->top]=t;
}

void Pop(struct Stack* S)
{

    if(S->top==0)
    {
        cout<<"stos jest pusty"<<endl;
    }
    else
    {
        S->top--;
    }
}
void print(struct Stack* S)
{
    cout<<S->stos[S->top]<<endl;

}
int main()
{
    Stack* s = new Stack;
    Stack_init(s);
    Push(s,23);
    Push(s,11);
    Push(s,3);
    print(s);
    Pop(s);
    print(s);

    return 0;
}
*/

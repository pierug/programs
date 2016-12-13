#include <iostream>

using namespace std;


struct c_list{

    struct element_c_list{
        int num;
        struct element_c_list *next;
        struct element_c_list *previous;
    };

    c_list(){
        first = NULL;
        wsk = NULL;
        i=0;
    }
    int i;
    element_c_list *first;
    element_c_list *wsk;

    void add(int t)
    {
        i++;
        element_c_list *NewEle = new element_c_list();
        NewEle->num = t;
        if(this->wsk==NULL)
        {
            this->wsk=NewEle;
            this->wsk->next==NULL;
            this->wsk->previous==NULL;
        }
        else
        {
            if(this->wsk->next==NULL)
            {
                this->wsk->next=NewEle;
                NewEle->next=this->wsk;
                NewEle->previous=this->wsk;
                this->wsk->previous=NewEle;
                this->wsk=NewEle;
            }
            else
            {
                this->wsk->next->previous=NewEle;
                NewEle->next=this->wsk->next;
                NewEle->previous=this->wsk;
                this->wsk->next = NewEle;
                this->wsk=NewEle;
            }
        }
    }

    element_c_list* searchh(struct element_c_list* ecl, int t, int j)
    {
        if(ecl==NULL || j>i)
            return NULL;
        else
        {
            if(ecl->num==t)
                return ecl;
            else
            {
                j++;
                return searchh(ecl->next,t,j);
            }

        }
    }

    void get_rid_off(int t)
    {
        if(this->wsk==NULL)
        {
            cout<<"NIMA"<<endl;
        }
        else
        {
            element_c_list *sear_ele = searchh(this->wsk,t,0);
            if(sear_ele==NULL)
            {
                cout<<"NIMA"<<endl;
            }
            else
            {
                i--;

                sear_ele->next->previous=sear_ele->previous;
                sear_ele->previous->next=sear_ele->next;
                sear_ele = NULL;
            }
        }
    }

    void print_c_list(void)
    {
        if(this->wsk==NULL)
            cout<<"NIMA"<<endl;
        else
        {
            element_c_list *tmp = this->wsk;
            for(int j=0;j<i;j++)
            {
                cout<<tmp->num<<endl;
                tmp = tmp->previous;
            }
        }
    }

};
int main()
{
    c_list l;
    l.add(2);
    l.add(4);
    l.add(7);
    l.add(9);
    l.add(4);
    l.add(10);
    l.add(23);
    l.print_c_list();
    cout<<"!!!!!!!!!!!!!!"<<endl;
    l.get_rid_off(4);
    l.get_rid_off(4);
    l.add(4);
    l.get_rid_off(4);
    cout<<"!!!!!!!!!!!!!!"<<endl;
    l.print_c_list();


    return 0;
}

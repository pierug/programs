#include <iostream>

using namespace std;

struct tree{

    struct treeElem{
        struct treeElem* left;
        struct treeElem* right;
        struct treeElem* previous;
        int num;
    };

    tree()
    {
        parent=NULL;

    }


    treeElem* parent;

    void postorder(struct treeElem *first)
    {
        if (first != NULL)
        {
            postorder(first->left);
            postorder(first->right);
            cout <<" "<< first->num<<", ";
        }
    }

    void preorder(struct treeElem *first)
    {
        if (first != NULL)
        {
            cout <<" "<< first->num<<", ";
            preorder(first->left);
            preorder(first->right);
        }

    }
    void inorder(struct treeElem *first)
    {
        if (first != NULL)
        {
            inorder(first->left);
            cout <<" "<< first->num<<", ";
            inorder(first->right);
        }

    }
    void add_Child(struct treeElem *start, int t)
    {
        if(t<start->num)
        {
            if(start->left==NULL)
            {
                treeElem* newElem = new treeElem();
                newElem->num=t;
                newElem->left=NULL;
                newElem->right=NULL;
                newElem->previous=start;
                start->left=newElem;
            }
            else
            {
                add_Child(start->left,t);
            }

        }
        else
        {
            if(start->right==NULL)
            {
                treeElem* newElem = new treeElem();
                newElem->num=t;
                newElem->left=NULL;
                newElem->right=NULL;
                newElem->previous=start;
                start->right=newElem;
            }
            else
            {
                add_Child(start->right,t);
            }
        }
    }

    void add(int t)
    {
        treeElem* newElem = new treeElem();
        newElem->num = t;

        if(this->parent==NULL)
            this->parent = newElem;
        else
            add_Child(this->parent,t);

    }

    treeElem *search_child(struct treeElem *start, int t)
    {
        if (start==NULL)
        {
            return NULL;
        }
        if(t==start->num)
        {
            return start;
        }
        if(t<start->num)
        {
            return search_child(start->left,t);
        }
        else
        {
            return search_child(start->right,t);
        }
        return NULL;
    }
    int getRidOff(int t)
    {
        if(this->parent==NULL)
            cout << " drzewo puste" << endl;
        else
        {
            treeElem* searchElem = search_child(this->parent,t);
            cout << " !!!!!!!!! "<<searchElem->num<<" !!!!!!!!! "<<endl;
            if(searchElem==NULL)
                cout << "nie znaleziono elementu do usinieca" << endl;
            else
            {
                if(searchElem->left==NULL && searchElem->right==NULL)
                {
                    if (searchElem->previous->right == searchElem)
                        searchElem->previous->right = NULL;
                    else
                        searchElem->previous->left = NULL;
                }
                else if(searchElem->left==NULL || searchElem->right==NULL)
                {
                    if(searchElem->left==NULL)
                    {
                        searchElem->num = searchElem->right->num;
                        searchElem->right = NULL;
                    }
                    else if (searchElem->right==NULL)
                    {
                        searchElem->num = searchElem->left->num;
                        searchElem->left = NULL;
                        delete searchElem->left;
                    }
                }
                else
                {
                    treeElem *tmp = searchElem->left;
                    treeElem *papa = searchElem;
                    while(tmp->right != NULL)
                    {
                        papa = tmp;
                        tmp = tmp->right;
                    }
                    searchElem->num = tmp->num;
                    if(tmp->left==NULL && tmp->right==NULL)
                    {
                        if(papa->left == tmp)
                            papa->left = NULL;
                        else
                            papa->right = NULL;
                        delete tmp;
                    }
                    else if(tmp->left==NULL || tmp->right==NULL)
                    {
                        if(tmp->left==NULL)
                        {
                            tmp->num = tmp->right->num;
                            tmp->right = NULL;
                        }
                        else if (tmp->right==NULL)
                        {
                            tmp->num = tmp->left->num;
                            tmp->left = NULL;
                        }
                    }
                }
            }
        }
    }
};

int main()
{
    tree tr;
    tr.add(8);
    tr.add(9);
    tr.add(3);
    tr.add(2);
    tr.add(1);
    int s;
    tr.add(5);
    tr.add(10);
    tr.add(4);
    tr.add(6);

    cout<<" "<<endl;
    cout<<"inorder "<<endl;
    tr.inorder(tr.parent);
    cout<<" "<<endl;
    cout<<"preorder "<<endl;
    tr.preorder(tr.parent);
    cout<<" "<<endl;
    cout<<"postorder "<<endl;
    tr.postorder(tr.parent);

    s = tr.getRidOff(3);
    cout<<" "<<endl;
    cout<<"inorder "<<endl;
    tr.inorder(tr.parent);
    cout<<" "<<endl;
    cout<<"preorder "<<endl;
    tr.preorder(tr.parent);
    cout<<" "<<endl;
    cout<<"postorcer "<<endl;
    tr.postorder(tr.parent);


    return 0;
}

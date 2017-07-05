#ifndef COMPOSITE_H
#define COMPOSITE_H
#include <iostream>
#include <vector>

using namespace std;
class TreeComponent{
public:
    virtual void print()=0;
};

class Leaf: public TreeComponent{
private:
    int value;
public:
    Leaf(int v){
        value = v;
    }
    void print(){
        cout<< "I'm "<<value<<" leaf"<<endl;
    }
};

class TreeComposite: public TreeComponent{

private:

public:
    vector <TreeComponent *> children;
    void add(TreeComponent * c){
        children.push_back(c);
    }
    void print(){
        for(int i=0;i<children.size();i++){
            children[i]->print();
        }
    }
};

#endif // COMPOSITE_H

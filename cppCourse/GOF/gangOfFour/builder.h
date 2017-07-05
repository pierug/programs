#ifndef BUILDER_H
#define BUILDER_H

#include<iostream>
using namespace std;
class Product{
public:
    void addPart(string part){
        cout<<part<<endl;
    }
};

class Builder{
public:
    virtual void buildPartA(Product* product)=0;
    virtual void buildPartB(Product* product)=0;
    ~Builder(){}
};

class ConcreteBuilder: public Builder{
    virtual void buildPartA(Product* product){
        product->addPart("A");
    }

    virtual void buildPartB(Product* product){
        product->addPart("B");
    }
};

class Director{
private:
    Builder* builder;
public:
    Director(){
        builder = new ConcreteBuilder();
    }
    ~Director(){
        delete builder;
    }
    void construct(){
        builder->buildPartA(NULL);
        builder->buildPartB(NULL);
    }
};


#endif // BUILDER_H

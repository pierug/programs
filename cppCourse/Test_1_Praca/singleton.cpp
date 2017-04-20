#include "singleton.h"
#include <iostream>
#include <vector>

using namespace std;


Singleton* Singleton::instance = NULL;

Singleton *Singleton::getInstance()
{
    if(Singleton::instance==NULL){
        Singleton::instance = new Singleton;
    }
    return instance;
}

void Singleton::disp()
{
    cout<<"OK"<<endl;
}

int* Singleton::makeFibonaci(int n)
{
    int* array;
    array = new int[n];
    array[0]=0;
    array[1]=1;
    for(int i=2;i<n;i++){
        array[i]=array[i-1]+array[i-2];

    }
    return array;
}

int* Singleton::makeRecFibonaci(int i,int n, int *array)
{

    if(i==0){
        delete array;
        array = new int[n];
        array[0]=0;
    }else if(i==1){
        array[1]=1;
    }else{
        array[i]=array[i-1]+array[i-2];
    }
    i++;
    if((i==n)){
        return array;
    }else{
        makeRecFibonaci(i,n,array);
    }
}

void Singleton::dispArray(int n, int *array){
    for (int i = 0; i < n; ++i) {
        cout<<array[i]<<endl;
    }
}

vector<string> Singleton::splitStringTxt(string txt,const char pattern)
{

    vector<string> result;
    result.clear();
    string tmp="";

    for (int i = 0; i < txt.length(); ++i) {
        if(txt.at(i)==pattern){
            result.push_back(tmp);
            tmp="";
        }else{
            if(!((tmp=="")&&(txt.at(i)==' '))){
                tmp+=txt.at(i);
            }
        }
    }
    if(txt.at(txt.length()-1)!=pattern){
        result.push_back(tmp);
    }

    return result;

}

Singleton::~Singleton()
{
    delete instance;
    Singleton::instance = NULL;
}


void Singleton::dispSplitTxt(const vector<string> stringVec){

    for (int i = 0; i < stringVec.size(); ++i) {
        cout<<stringVec[i]<<endl;
    }
}

void Singleton::quicksort(int* array, int left, int right){
    int centerIndex = (left+right)/2;
    int centerElement = array[centerIndex];
    int l=left;
    int r=right;

    do{
        while(array[l]<centerElement) l++;
        while(array[r]>centerElement) r--;

        if(l<=r){
            swap(array[l],array[r]);
            r--;
            l++;
        }

    }while(l<=r);

    if(l<right){
       quicksort(array,l,right);
    }
    if(r>left){
       quicksort(array,left,r);
    }
}

void Singleton::Karp_Rabin(string txt, string patern)
{
    int txtLenght = txt.length();
    int paternLenght = patern.length();

    int k_patern= 0;
    int k_txt= 0;
    for (int i = 0; i < paternLenght; i++) {
        k_patern+=patern.at(i);
        k_txt+=txt.at(i);
    }
    k_patern%=255;
    k_txt%=255;
    int j=0;
    for (int i = 0; i < txtLenght-paternLenght+1; i++) {
        if(i!=0){
            k_txt=(k_txt+txt.at(i+paternLenght-1)-txt.at(i-1))%255;
        }
        j=0;
        if(k_txt==k_patern){
            for(j=0;j<paternLenght;j++){
                if(patern.at(j)!=txt.at(j+i)){
                    break;
                }
            }
        }
        if(j==paternLenght){
            cout<<"Znaleziono tekst na miejscu index="<<i<<endl;
        }
    }
}

void Singleton::insertsort(int lenght, int* array){
    int j=0,tmp;
    for (int i = 1; i < lenght; ++i) {
        j=i-1;
        tmp=array[i];
        while((j>=0)&&(tmp>array[j])){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=tmp;
    }
}

void Singleton::selectionsort(int lenght, int* array){
    int maxIndex;
    for (int i = 0; i < lenght-1; ++i) {
        maxIndex=i;
        for(int j=i;j<lenght;j++){
            if(array[maxIndex]>array[j]){
                maxIndex=j;
            }
        }
        if(maxIndex!=i) swap(array[maxIndex],array[i]);
    }
}

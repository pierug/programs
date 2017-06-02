#include "lotto.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <utility>
#define RANDOM_NUMBERS_SIZE     6000
#define MAX_LUCKY_NUMBER        48
#define MIN_LUCKY_NUMBER        1
using namespace std;
Lotto::Lotto()
{

}

int* Lotto::createLuckySix()
{
    int* luckySix= new int[6];
    for(int i=0;i<6;i++){
        luckySix[0];
    }
    int tmp;
    int oddNum=0;
    luckySix[0]=createRandomNumber();
    for(int i=1;i<6;i++){
        tmp=createRandomNumber();
        for(int i=0;i<6;i++){
            if(tmp==luckySix[i]){
                i= -1;
                tmp=createRandomNumber();
            }
        }
        luckySix[i] = tmp;

    }
    sort(0,6,luckySix);
    return luckySix;
}

void Lotto::sort(int left, int right, int* array)
{
    int l=left;
    int r=right;
    int centerIndex = (left+right)/2;
    int centerElement = array[centerIndex];

    do{
        while(array[l]<centerElement) l++;
        while(array[r]>centerElement) r--;

        if(l<=r){
            swap(array[l],array[r]);
            l++;
            r--;
        }

    }while(l<=r);

    if(left<r) sort(left,r,array);
    if(right>l) sort(l,right,array);
}

int Lotto::createRandomNumber()
{
    time_t t = time(NULL);
    int result = (int)(((rand()+t)%48) + 1);
    cout<<"result: "<<result<<endl;
    return result;
}

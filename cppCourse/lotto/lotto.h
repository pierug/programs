#ifndef LOTTO_H
#define LOTTO_H

#include <vector>

class Lotto
{
public:
    Lotto();
    int* createLuckySix();
private:
    int createRandomNumber();
    void sort(int left, int right, int* array);
};

#endif // LOTTO_H

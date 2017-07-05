#ifndef EFFORT_H
#define EFFORT_H


class Effort
{
private:
    int withGetSet;
public:
    Effort();
    int withoutGetSet;

    void efforTestWith();
    void efforTestWithout();

    int getWithGetSet() const;
    void setWithGetSet(int value);
};

#endif // EFFORT_H

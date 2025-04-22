#ifndef MONEY_H
#define MONEY_H

#include <iostream>

class Money {
private:
    int dollars;
public:
    Money();
    Money(int d);
    int getMoney() const;
    void setMoney(int d);
};

#endif
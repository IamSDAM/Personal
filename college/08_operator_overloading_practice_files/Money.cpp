#include "Money.h"

Money::Money(): dollars(0)
{

}
Money::Money(int d): dollars(d)
{
    
}
int Money::getMoney() const
{
    return dollars;
}
void Money::setMoney(int d)
{
    dollars = d;
}
//
// Created by Oleg on 16.09.2017.
//

#ifndef LB2_GOODS_H
#define LB2_GOODS_H


#include <iostream>
using namespace std;

class Goods {

protected:
    char *name;
    int amount;
    char *location;

public:

    Goods();
    Goods(char *rName, int rAmount, char *rLocation);
    Goods(const Goods &obj);

    void setGoodsOption(char *rName, int rAmount, char *rLocation);
    void setName(char *rName);
    void setAmount(int rAmount);
    void setLocation(char *rLocation);

    char *getName() const;
    int getAmount() const;
    char *getLocation() const;

    ~Goods();

};


#endif //LB2_GOODS_H

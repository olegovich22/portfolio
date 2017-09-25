//
// Created by Oleg on 16.09.2017.
//

#ifndef LB1_GOODS_H
#define LB1_GOODS_H



#include <iostream>
using namespace std;

class Goods {

private:
    char *name;
    int amount;
    char *location;

public:

    Goods();
    Goods(char*,int,char*);
    Goods(const Goods &obj);

    void showCopyWork(Goods aGoods);

    void setGoodsOption(char *rName, int rAmount, char *rLocation);
    void setName(char *rName);
    void setAmount(int rAmount);
    void setLocation(char *rLocation);

    char *getName() const;
    int getAmount() const;
    char *getLocation() const;

    ~Goods();

};




#endif //LB1_GOODS_H

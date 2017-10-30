//
// Created by Oleg on 20.09.2017.
//

#ifndef LW3_GOODS_H
#define LW3_GOODS_H


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

    Goods& operator = (const Goods &obj1);
    Goods& operator ++ ();
    Goods& operator ++ (int i);
    friend ostream& operator << (ostream& os, Goods& data);
    friend istream& operator >> (istream& os, Goods& data);

    void setGoodsOption(char *rName, int rAmount, char *rLocation);
    void setName(char *rName);
    void setAmount(int rAmount);
    void setLocation(char *rLocation);

    char *getName() const;
    int getAmount() const;
    char *getLocation() const;

    virtual void bestBefore() = 0;

    virtual ~Goods();

};


//int operator () (int a, int b);


#endif //LW3_GOODS_H

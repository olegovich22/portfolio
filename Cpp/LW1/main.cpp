#include <iostream>


#include "helpFunctions.h"
#include "Goods.h"
using namespace std;

int main() {

    Goods aGoods;

    char* name=aGoods.getName();
    int amount=aGoods.getAmount();
    char* location=aGoods.getLocation();

    cout<<"name: "<<name<<"\n"
        <<"amount: "<<amount<<"\n"
        <<"location: "<<location<<"\n\n";

    cout<<"Please enter name of goods\n";
    aGoods.setName(getString());
    cout<<"Please enter numb of goods\n";
    aGoods.setAmount(getInt());
    cout<<"Please enter location of goods\n";
    aGoods.setLocation(getString());

    name=aGoods.getName();
    amount=aGoods.getAmount();
    location=aGoods.getLocation();

    cout<<"name: "<<name<<"\n"
        <<"amount: "<<amount<<"\n"
        <<"location: "<<location<<"\n\n";


    aGoods.showCopyWork(aGoods);

    name=aGoods.getName();
    amount=aGoods.getAmount();
    location=aGoods.getLocation();
    cout<<"LASTname: "<<name<<"\n"
        <<"LASTamount: "<<amount<<"\n"
        <<"LASTlocation: "<<location<<"\n\n";


    return 1;
}
//
// Created by Oleg on 14.09.2017.
//

#include "clases.h"
#include <iostream>
#include <string.h>
using namespace std;

//constructor and ~constructor
Goods::Goods()
{
    char aName[]="Unknown";
    char alocation[]="Unknown";
    setGoodsOption(aName, 0, alocation);
}

Goods::Goods(char* aName, int anAmount, char *aLocation)
{
    setGoodsOption(aName, anAmount, aLocation);
}

Goods::Goods(const Goods &obj)
{
    *this=obj;
}

Goods::~Goods()
{
    delete[] name;
    delete[] location;
}

//setFunctions
void Goods::setGoodsOption(char *rName, int rAmount, char *rLocation)
{
    setName(rName);
    amount=rAmount;
    setLocation(rLocation);
}

void Goods::setName(char *rName)
{
    name=new char[strlen(rName)+1];
    strcpy(name, rName);
}

void Goods::setAmount(int rAmount)
{
    amount=rAmount;
}

void Goods::setLocation(char *rLocation)
{
    location=new char[strlen(rLocation)+1];
    strcpy(location, rLocation);
}

//getFunctions
char *Goods::getName() const
{
    return name;
}

int Goods::getAmount() const
{
    return amount;
}

char *Goods::getLocation() const
{
    return location;
}


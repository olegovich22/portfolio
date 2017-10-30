//
// Created by Oleg on 14.09.2017.
//

#include "Goods.h"
#include <iostream>
#include <string.h>
using namespace std;

//constructor and ~constructor
Goods::Goods()
{
    name= new char[8];
    strcpy(name, "Unknown");

    amount=0;

    location= new char[8];
    strcpy(location, "Unknown");
}

Goods::Goods(char* aName, int anAmount, char *aLocation)
{
    setGoodsOption(aName, anAmount, aLocation);
}

Goods::Goods(const Goods &obj)
{
    name=new char[strlen(obj.name)];
    strcpy(name, obj.name);

    amount=obj.amount;

    location=new char[strlen(obj.location)];
    strcpy(location, obj.location);
}

Goods::~Goods()
{
    delete[] name;
    delete[] location;
}


//operators
Goods& Goods::operator = (const Goods &obj1)
{
    setName(obj1.name);
    amount=obj1.amount;
    setLocation(obj1.location);

    return *this;
}

Goods& Goods::operator ++ ()
{
    amount=amount+1;
    return *this;
}

Goods& Goods::operator ++ (int i)
{
    amount=amount+1;
    return *this;
}

ostream& operator << (ostream& os, Goods& data)
{
    cout<<"Name: "<<data.name<<endl;
    cout<<"Amount: "<<data.amount<<endl;
    cout<<"Location: "<<data.location<<endl;
    return os;
}
istream& operator >> (istream& os, Goods& data)
{
    cout<<"Name: \n";cin>>data.name;
    cout<<"Amount: \n";cin>>data.amount;
    cout<<"Location: \n";cin>>data.location;
    return os;
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
    if(name)
    {
        delete [] name;
    }
    name=new char[strlen(rName)+1];
    strcpy(name, rName);
}

void Goods::setAmount(int rAmount)
{
    amount=rAmount;
}

void Goods::setLocation(char *rLocation)
{
    if(location)
    {
        delete [] location;
    }
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


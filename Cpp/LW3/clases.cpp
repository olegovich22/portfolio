//
// Created by Oleg on 20.09.2017.
//

#include "clases.h"
#include "helpFunctions.h"
#include <iostream>
// Created by Oleg on 16.09.2017.
//


//class FastCorrupt______________________________________________________________________________

//Constructors
FastCorrupt::FastCorrupt(int anExpiration, int aDateProduction, char* aName, int anAmount, char* aLocation):Goods(aName, anAmount, aLocation)
{
    setFastCorruptOptns(anExpiration, aDateProduction);
}

FastCorrupt::FastCorrupt(const FastCorrupt &obj)
{
    *this=obj;
}

FastCorrupt::~FastCorrupt()
{

}



//operators
FastCorrupt* FastCorrupt::operator = (const FastCorrupt *obj1)
{
    expiration=obj1->expiration;
    dateProduction=obj1->dateProduction;
    *this=*obj1;

    return this;
}

bool FastCorrupt::operator > (const FastCorrupt &obj1)
{
    if(dateProduction>obj1.dateProduction)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool FastCorrupt::operator < (const FastCorrupt &obj1)
{
    if(dateProduction<obj1.dateProduction)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

ostream& operator << (ostream& os, FastCorrupt& data)
{
    time_t dateProduction1=data.dateProduction*3600;

    cout<<"Name: "<<data.name<<endl;
    cout<<"Amount: "<<data.amount<<endl;
    cout<<"Location: "<<data.location<<endl;
    cout<<"Date production: "<<ctime(&dateProduction1);
    cout<<"Expiration: ";convertHours(data.expiration);

    return os;
}

istream& operator >> (istream& os, FastCorrupt& data)
{

    cout<<"Name: \n";data.setName(getString());
    cout<<"Amount: \n";data.setAmount(getInt());
    cout<<"Location: \n";data.setLocation(getString());
    cout<<"Expiration(in hour): \n";cin>>data.expiration;
    cout<<"Date production HH DD/MM/YYYY: \n";data.dateProduction=getTimeProduction();
    return os;
}


//functions
void FastCorrupt::setFastCorruptOptns(int anExpiration, int aDateProduction)
{
    expiration=anExpiration;
    dateProduction=aDateProduction;
}

void FastCorrupt::setExpiration(int anExpiration)
{
    expiration=anExpiration;
}

void FastCorrupt::setDateProduction(int aDateProduction)
{
    dateProduction=aDateProduction;
}


void FastCorrupt::bestBefore(FastCorrupt *obj)
{
    int expiration=obj->expiration;
    time_t date=obj->dateProduction*3600;
    time_t expDate=date+expiration*3600;

    int uHave=(expDate-time(0))/3600;

    cout<<"Date production: "<<ctime(&date)
        <<"Term suitability: "<<expiration<<" hour\n";
    cout<<"Expiration date: "<<ctime(&expDate);
    cout<<"U have: ";
    convertHours(uHave);
}


int FastCorrupt::getExpiration() const
{
    return expiration;
}

int FastCorrupt::getDateProduction() const
{
    return dateProduction;
}




//class Drugs_____________________________________________________________________________________________________________

//constructors
Drugs::Drugs (int aTemp, int aHumidity, int anExpiration, int aDateProduction, char *aName, int anAmount, char *aLocation):FastCorrupt(anExpiration, aDateProduction, aName, anAmount, aLocation)
{
    setDrugsOption(aTemp, aHumidity);
}

Drugs::~Drugs()
{

}

Drugs::Drugs(const Drugs &obj)
{
    *this=obj;
}



//operators
Drugs* Drugs::operator = (const Drugs *obj1)
{
    temp=obj1->temp;
    humidity=obj1->humidity;
    *this=*obj1;

    return this;
}

bool Drugs::operator > (const Drugs &obj1)
{
    if(this->temp>obj1.temp && this->expiration>obj1.expiration)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

bool Drugs::operator < (const Drugs &obj1)
{
    if(this->temp<obj1.temp && this->expiration<obj1.expiration)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

ostream& operator << (ostream& os, Drugs& data)
{
    time_t dateProduction1=data.dateProduction*3600;

    cout<<"Name: "<<data.name<<endl;
    cout<<"Amount: "<<data.amount<<endl;
    cout<<"Location: "<<data.location<<endl;
    cout<<"Date production: "<<ctime(&dateProduction1);
    cout<<"Expiration: ";convertHours(data.expiration);
    cout<<"Keep temp: "<<data.temp<<endl;
    cout<<"Humidity: "<<data.humidity<<endl;

    return os;
}

istream& operator >> (istream& os, Drugs& data)
{

    cout<<"Name: \n";data.setName(getString());
    cout<<"Amount: \n";data.setAmount(getInt());
    cout<<"Location: \n";data.setLocation(getString());
    cout<<"Expiration(in hour): \n";data.setExpiration(getInt());
    cout<<"Date production HH DD/MM/YYYY: \n";data.setDateProduction(getTimeProduction());
    cout<<"Temp keeping: \n";cin>>data.temp;
    cout<<"Humidity: \n";cin>>data.humidity;

    return os;
}

//functions
void Drugs::setDrugsOption(int aTemp, int aHumidity)
{
    temp=aTemp;
    humidity=aHumidity;
}

void Drugs::setTemp(int aTemp)
{
    temp=aTemp;
}

void Drugs::setHumidity(int aHumidity)
{
    humidity=aHumidity;
}


void Drugs::bestBefore(Drugs *obj)
{
    int temp=obj->temp;
    int humidity=obj->humidity;
    time_t expiration=obj->expiration;
    time_t date=obj->dateProduction*3600;
    time_t expDate=date+expiration*3600;

    int uHave=(expDate-time(0))/3600;

    cout<<"Keep temperature: "<<temp<<" C"<<endl
        <<"Humidity: "<<humidity<<"%"<<endl
        <<"Date production: "<<ctime(&date)
        <<"Term suitability: "<<expiration<<" hour"<<endl;
    cout<<"Expiration date: "<<ctime(&expDate);
    cout<<"U have: ";
    convertHours(uHave);

}


int Drugs::getTemp() const
{
    return temp;
}

int Drugs::getHumidity() const
{
    return humidity;
}


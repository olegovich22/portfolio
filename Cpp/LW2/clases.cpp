#include "clases.h"//
#include "helpFunctions.h"
// Created by Oleg on 16.09.2017.
//


//class FastCorrupt_______________________________________________________________

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


//class Drugs________________________________________________________________________________________________


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


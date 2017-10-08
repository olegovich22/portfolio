//
// Created by Oleg on 20.09.2017.
//

#ifndef LW3_CLASES_H
#define LW3_CLASES_H


#include <ctime>
#include "Goods.h"



class FastCorrupt : public Goods
{

protected:
    int expiration;
    int dateProduction;
private:
    void setFastCorruptOptns(int anExpiration, int aDateProduction);
public:

    //constructors
    FastCorrupt(): expiration(0), dateProduction(0) {}
    FastCorrupt(int anExpiration, int aDateProduction, char *aName, int anAmount, char *aLocation);
    FastCorrupt(const FastCorrupt &obj);

    //operators
    FastCorrupt* operator = (const FastCorrupt *obj1);
    bool operator > (const FastCorrupt &obj1);
    bool operator < (const FastCorrupt &obj1);
    friend ostream& operator << (ostream& os, FastCorrupt& data);
    friend istream& operator >> (istream& os, FastCorrupt& data);

    //functions
    void setExpiration(int anExpiration);
    void setDateProduction(int aDateProduction);

    virtual void bestBefore(FastCorrupt *obj);

    int getExpiration() const;
    int getDateProduction() const;

    //destructor
    ~FastCorrupt();

};


class Drugs: public FastCorrupt
{

protected:
    int temp;
    int humidity;
public:

    //constructors
    Drugs(): temp(0), humidity(0) {}
    Drugs(int aTemp, int aHumidity, int anExpiration, int aDateProduction, char *aName, int anAmount, char *aLocation);
    Drugs(const Drugs &obj);

    //operators
    Drugs* operator = (const Drugs *obj1);
    bool operator > (const Drugs &obj1);
    bool operator < (const Drugs &obj1);
    friend ostream& operator << (ostream& os, Drugs& data);
    friend istream& operator >> (istream& os, Drugs& data);


    //functions
    void setDrugsOption(int aTemp, int aHumidity);
    void setTemp(int aTemp);
    void setHumidity(int aHumidity);

    virtual void bestBefore(Drugs *obj);

    int getTemp() const;
    int getHumidity() const;

    //destructor
    ~Drugs();
};



#endif //LW3_CLASES_H

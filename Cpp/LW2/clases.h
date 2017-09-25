//
// Created by Oleg on 25.09.2017.
//

#ifndef LB2_CLASES_H
#define LB2_CLASES_H

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
    FastCorrupt(): expiration(0), dateProduction(0) {}
    FastCorrupt(int anExpiration, int aDateProduction, char *aName, int anAmount, char *aLocation);
    FastCorrupt(const FastCorrupt &obj);

    void setExpiration(int anExpiration);
    void setDateProduction(int aDateProduction);


    void bestBefore(FastCorrupt *obj);


    int getExpiration() const;
    int getDateProduction() const;

    ~FastCorrupt();

};


class Drugs: public FastCorrupt
{

protected:
    int temp;
    int humidity;
public:

    Drugs(): temp(0), humidity(0) {}
    Drugs(int aTemp, int aHumidity, int anExpiration, int aDateProduction, char *aName, int anAmount, char *aLocation);
    Drugs(const Drugs &obj);

    void setDrugsOption(int aTemp, int aHumidity);
    void setTemp(int aTemp);
    void setHumidity(int aHumidity);


    void bestBefore(Drugs *obj);


    int getTemp() const;
    int getHumidity() const;

    ~Drugs();
};


#endif //LB2_CLASES_H

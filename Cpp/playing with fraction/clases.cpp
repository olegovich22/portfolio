//
// Created by Oleg on 14.10.2017.
//
#include <iostream>
#include <cmath>
#include "clases.h"
#include "functions.h"

using namespace std;

void Fraction::setFraction(int newNum, int newDen)
{
    numerator=newNum;
    denominator=newDen;
}

void Fraction::setNumerator(int newNum)
{
    numerator=newNum;
}

void Fraction::setDenominator(int newDen)
{
    denominator=newDen;
}

int Fraction::getNumerator()
{
    return numerator;
}

int Fraction::getDenominator()
{
    return denominator;
}

Fraction& Fraction::operator = (const Fraction &obj)
{
    this->denominator=obj.denominator;
    this->numerator=obj.numerator;
    return *this;
}
Fraction& Fraction::operator + (Fraction &obj)
{
    if (this->denominator==obj.denominator)
    {
        this->numerator+=obj.numerator;
    } else
    {
        int time=this->denominator;
        this->numerator*=obj.denominator;
        this->denominator*=obj.denominator;
        obj.numerator*=time;

        this->numerator+=obj.numerator; //adding

        obj.numerator/=time;
    }
    return *this;
}

Fraction& Fraction::operator - (Fraction &obj)
{
    if (this->denominator==obj.denominator)
    {
        this->numerator-=obj.numerator;
    } else
    {
        int time=this->denominator;
        this->numerator*=obj.denominator;
        this->denominator*=obj.denominator;
        obj.numerator*=time;

        this->numerator-=obj.numerator; //adding

        obj.numerator/=time;
    }
    return *this;
}

Fraction& Fraction::operator * (const Fraction &obj)
{
    this->numerator*=obj.numerator;
    this->denominator*=obj.denominator;
    return *this;
}

Fraction& Fraction::operator / (const Fraction &obj)
{
    this->numerator*=obj.denominator;
    this->denominator*=obj.numerator;
    return *this;
}

ostream& operator << (ostream& os, Fraction& data)
{
    cout<<data.numerator;
    cout<<"/";
    cout<<data.denominator;
    cout<<" ";
    return os;
}

istream& operator >> (istream& os, Fraction& data)
{
    cout<<"Please enter fraction options\n";
    cout<<"Numerator:\n";data.setNumerator(getInt());
    cout<<"Denominator:\n";data.setDenominator(getInt());

    return os;
}

bool Fraction::operator < (Fraction &obj)
{
    bool result=(this->numerator*obj.denominator)<(obj.numerator*this->denominator);
    return result;

}

bool Fraction::operator > (Fraction &obj)
{
    bool result=(this->numerator*obj.denominator)>(obj.numerator*this->denominator);
    return result;

}


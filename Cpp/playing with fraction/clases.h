//
// Created by Oleg on 14.10.2017.
//

#include <iostream>
using namespace std;

#ifndef LW4_CLASES_H
#define LW4_CLASES_H


class Fraction
{
public:
    int numerator;
    int denominator;
public:
    Fraction(int numerator1=0, int denominator1=1):numerator(numerator1), denominator(denominator1){}
    Fraction(const Fraction &obj){*this=obj;}
    ~Fraction(){}

    void setFraction(int newNum, int newDen);
    void setNumerator(int newNum);
    void setDenominator(int newDen);

    int getNumerator();
    int getDenominator();

    Fraction& operator = (const Fraction &obj);
    Fraction& operator + (Fraction &obj);
    Fraction& operator - (Fraction &obj);
    Fraction& operator * (const Fraction &obj);
    Fraction& operator / (const Fraction &obj);
    bool operator < (Fraction &obj);
    bool operator > (Fraction &obj);
    friend ostream& operator << (ostream& os, Fraction& data);
    friend istream& operator >> (istream& os, Fraction& data);

};




#endif //LW4_CLASES_H

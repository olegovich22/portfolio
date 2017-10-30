//
// Created by Oleg on 14.10.2017.
//
#include <iostream>
#include <ctime>
#include <vector>
#include <iterator>
#include <algorithm>

#include "functions.h"

using namespace std;

int getInt()//get int from user
{
    int chek=0;
    int answer=0;
    do
    {
        chek=scanf("%i", &answer);
        fflush(stdin);
        if (chek!=1)
        {
            printf("ERROR. Please enter int.\n");
        }
    }while(chek!=1);

    return answer;
}

void increaseVector(vector <Fraction> &vec,  unsigned int sizeIncrease)
{
    unsigned int size=vec.size();
    try {

        vec.resize(size+sizeIncrease);
        generate(vec.begin()+size, vec.end(), generateRandomNumb);
    }
    catch(...)
    {
        cout<<"ERROR. Haven't enough memory for decreasing vector or another unexpected error.\n";
    }

}

vector <Fraction> newSortVector(const vector <Fraction> &vec, int sizeSort)
{
    vector <Fraction> newVec;
    newVec=vec;
    sort(newVec.begin(), newVec.begin()+sizeSort);

    return newVec;
}

Fraction generateRandomNumb()
{
    Fraction oleg(rand()%10, 1+rand()%10);
    return oleg;
}


//
// Created by Oleg on 16.09.2017.
//


#ifndef LB2_HELPFUNCTIONS_H
#define LB2_HELPFUNCTIONS_H

#include <iostream>
#include "clases.h"
#include "Goods.h"

using namespace std;

char* getString();//smart get string from user

int getInt();//get int from user

int getTimeProduction();// get time production from user in format "hh dd/mm/yyyy"

void convertHours(int uHave);//convert time in our in human read form


/*void bestBefore(Drugs *obj);
void bestBefore(FastCorrupt *obj);*/




#endif //LB2_HELPFUNCTIONS_H

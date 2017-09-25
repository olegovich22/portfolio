//
// Created by Oleg on 16.09.2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <ctime>
#include "clases.h"


using namespace std;

char* getString()//smart get string from user
{
    fflush(stdin);
    // growable buffer for chars
    char* buffer = NULL;

    // capacity of buffer
    unsigned int capacity = 0;

    // number of chars actually in buffer
    unsigned int n = 0;

    // character read or EOF
    int c;

    // iteratively get chars from standard input
    while ((c = fgetc(stdin)) != '\n' && c != EOF)
    {
        // grow buffer if necessary
        if (n + 1 > capacity)
        {
            // determine new capacity: start at 32 then double
            if (capacity == 0)
                capacity = 32;
            else if (capacity <= (UINT_MAX / 2))
                capacity *= 2;
            else
            {
                free(buffer);
                return NULL;
            }

            // extend buffer's capacity
            char *temp = (char *)realloc(buffer, capacity * sizeof(char));
            if (temp == NULL)
            {
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }

        // append current character to buffer
        buffer[n++] = c;
    }
    fflush(stdin);
    // return NULL if user provided no input
    if (n == 0 && c == EOF)
        return NULL;

    // minimize buffer
    char *minimal = (char *)malloc((n + 1) * sizeof(char));
    strncpy(minimal, buffer, n);
    free(buffer);

    // terminate string
    minimal[n] = '\0';

    // return string
    return minimal;

}

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

int getTimeProduction()// get time production from user in format "hh dd/mm/yyyy"
{
    char *time=getString();

    if(strlen(time)!=13)
        return 0;

    char* hour=new char[3];
    char *day=new char[3];
    char* month=new char[3];
    char *year=new char[5];

    hour[0]=time[0];
    hour[1]=time[1];
    hour[2]='\0';

    day[0]=time[3];
    day[1]=time[4];
    day[2]='\0';

    month[0]=time[6];
    month[1]=time[7];
    month[2]='\0';

    strcpy(year, time+9);

    int hour1=atoi(hour);
    int day1=atoi(day)-1;
    int month1=atoi(month);
    int year1=atoi(year);

    if(day1>31 || day1<0 || month1>12 || hour1>23)
    {
        return 0;
    }


    int generalCountOfDays=0;
    int leapYear=2;

    for (int i = 1970; i < year1; ++i) {

        if(leapYear==4)
        {
            generalCountOfDays+=1;
            leapYear=0;
        }

        leapYear++;

    }

    generalCountOfDays+=365*(year1-1970);


    int monthDay=0;
    for (int j = 1; j <month1; ++j) {

        if(j<8)
        {
            if(j&1)
            {
                monthDay+=31;
            } else if(j==2)
            {
                monthDay+=28;
            } else
            {
                monthDay+=30;
            }
        } else
        {
            if(j&1)
            {
                monthDay+=30;
            }
            else
            {
                monthDay+=31;
            }
        }
    }


    int result=(generalCountOfDays+monthDay+day1)*24+hour1;

    if(month1>3 && month1<11)
    {
        result=result-3;
    }
    else
    {
        result=result-2;
    }


    delete [] hour;
    delete [] day;
    delete [] month;
    delete [] year;

    return result;




}

void convertHours(int timeInOur)//convert time in our in human read form
{
    int year=timeInOur/8760;
    int month=(timeInOur-year*8760)/720;
    int day=(timeInOur-(year*8760+month*720))/24;
    int hour=timeInOur-(year*8760+month*720+day*24);

    if(timeInOur<=0)
    {
        cout<<"ERROR. Negative time\n";
    }
    if(year>0)
    {
        cout<<year<<" years ";
    }
    if(month>0)
    {
        cout<<month<<" month ";
    }
    if(day>0)
    {
        cout<<day<<" days ";
    }
    if(hour>0)
    {
        cout<<hour<<" hours ";
    }
    cout<<endl;
}





/*
void bestBefore(Drugs *obj) {

    int temp=obj->getTemp();
    int humidity=obj->getHumidity();
    int expiration=obj->getExpiration();
    time_t date=obj->getDateProduction()*3600;
    time_t expDate=date+expiration*3600;

    int uHave=(expDate-time(0))/3600;
    int year=uHave/8760;
    int month=(uHave-year*8760)/720;
    int day=(uHave-(year*8760+month*720))/24;
    int hour=uHave-(year*8760+month*720+day*24);

    cout<<"Keep temperature: "<<temp<<"°C"<<endl
        <<"Humidity: "<<humidity<<"%"<<endl
        <<"Date production: "<<ctime(&date)<<endl
        <<"Term suitability: "<<expiration<<" hour"<<endl
        <<"Expiration date: "<<ctime(&expDate);

    cout<<"U have: ";

    if(uHave<=0)
    {
        cout<<"Times is up! throw away this product\n";
    }
    if(year>0)
    {
        cout<<year<<" years ";
    }
    if(month>0)
    {
        cout<<month<<" month ";
    }
    if(day>0)
    {
        cout<<day<<" days ";
    }
    if(hour>0)
    {
        cout<<hour<<" hours ";
    }
    cout<<endl;

}

void bestBefore(FastCorrupt *obj)
{
    int expiration=obj->getExpiration();
    time_t date=obj->getDateProduction()*3600;
    time_t expDate=date+expiration*3600;

    int uHave=(expDate-time(0))/3600;
    int year=uHave/8760;
    int month=(uHave-year*8760)/720;
    int day=(uHave-(year*8760+month*720))/24;
    int hour=uHave-(year*8760+month*720+day*24);

    cout<<"Date production: "<<ctime(&date)<<endl
        <<"Term suitability: "<<expiration<<" hour"<<endl
        <<"Expiration date: "<<ctime(&expDate);

    cout<<"U have: ";

    if(uHave<=0)
    {
        cout<<"Times is up! throw away this product\n";
    }
    if(year>0)
    {
        cout<<year<<" years ";
    }
    if(month>0)
    {
        cout<<month<<" month ";
    }
    if(day>0)
    {
        cout<<day<<" days ";
    }
    if(hour>0)
    {
        cout<<hour<<" hours ";
    }
    cout<<endl;
}

 */
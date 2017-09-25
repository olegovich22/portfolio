#include <iostream>
#include <ctime>
#include <string.h>
using namespace std;

#include "clases.h"
#include "helpFunctions.h"

int main() {

    char *name="oleg";
    char *location="place";

    FastCorrupt badgoods;


    char *aName=badgoods.getName();
    int anAmount=badgoods.getAmount();
    char* aLocation=badgoods.getLocation();
    int expiration=badgoods.getExpiration();
    int dateProduction=badgoods.getDateProduction();
    //int temp=badgoods.getTemp();
    //int humidity=badgoods.getHumidity();

    cout<<"Name: "<<aName<<endl
        <<"Amount: "<<anAmount<<endl
        <<"Location: "<<aLocation<<endl
        <<"Expiration: "<<expiration<<endl
        <<"Date production: "<<dateProduction<<endl;
       // <<"Temp: "<<temp<<endl
        //<<"Humidity: "<<humidity<<endl<<endl;

    char *name2="oleg999";
    char *location2="place999";

    cout<<"\nPlease enter date production in HH DD/MM/YYYY format\n";
    int i=getTimeProduction();

    badgoods.setName(name2);
    badgoods.setAmount(1);
    badgoods.setLocation(location2);
    badgoods.setExpiration(240);
    badgoods.setDateProduction(i);
   // badgoods.setTemp(4);
    //badgoods.setHumidity(5);



    aName=badgoods.getName();
    anAmount=badgoods.getAmount();
    aLocation=badgoods.getLocation();
    expiration=badgoods.getExpiration();
    time_t dateProduction1=badgoods.getDateProduction()*3600;
    //temp=badgoods.getTemp();
    //humidity=badgoods.getHumidity();

    cout<<"Name: "<<aName<<endl
        <<"Amount: "<<anAmount<<endl
        <<"Location: "<<aLocation<<endl
        <<"Expiration: "<<expiration<<endl
        <<"Date production: "<<ctime(&dateProduction1);
        //<<"Temp: "<<temp<<endl
        //<<"Humidity: "<<humidity<<endl<<endl;

    cout<<"\nbestBeforeWork\n\n";
    badgoods.bestBefore(&badgoods);

    return 0;
}
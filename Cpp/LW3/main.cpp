#include <iostream>
using namespace std;

#include <ctime>

#include "Goods.h"
#include "clases.h"
#include "helpFunctions.h"

int main() {

    Drugs oleg1;
    Drugs oleg2;

    oleg1++;
    ++oleg2;

    cout<<oleg1;
    cout<<"\n";
    cout<<oleg2;

    cout<<"\n";
    cout<<"\n";


    oleg2.setAmount(55);
    oleg2.setTemp(33);


    oleg1=oleg2;

    cout<<oleg1;
    cout<<"\n";
    cout<<oleg2;



    return 0;
}
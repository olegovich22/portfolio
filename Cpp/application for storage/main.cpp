#include <iostream>
using namespace std;

#include <ctime>

#include "Goods.h"
#include "clases.h"
#include "helpFunctions.h"

int main() {

    Drugs drug1;
    Drugs drug2;

    ++drug1++;
    ++drug2;

    cout<<drug1;
    cout<<"\n";
    cout<<drug2;

    cout<<"\n";
    cout<<"\n";
    drug1=drug2;

    cout<<drug1;

    cin>>drug1;


    if(drug1>drug2)
    {
        cout<<"oleg1>oleg2\n";
    }

    cout<<"\n";

    cout<<drug1;





//    Goods *base[2];
//    Drugs child1;
//    FastCorrupt child2;
//
//    base[0]=&child1;
//    base[1]=&child2;
//
//    base[0]->bestBefore();
//    base[1]->bestBefore();

    return 0;
}
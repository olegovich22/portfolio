#include <iostream>
using namespace std;



#include "Goods.h"
#include "clases.h"


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
        cout<<"drug1>drug2\n";
    }

    cout<<"\n";

    cout<<drug1;






    return 0;
}
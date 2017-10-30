#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "clases.h"
#include "functions.h"

using namespace std;

int main() {

  Fraction oleg1(4, 1);
  Fraction oleg2(3, 1);
  Fraction oleg3(2, 1);
  Fraction oleg4(1, 1);

  vector <Fraction> oleg;


  oleg.push_back(oleg1);
  oleg.push_back(oleg2);
  oleg.push_back(oleg3);


  increaseVector(oleg, 2);

  vector <Fraction> newOleg;

    newOleg=newSortVector(oleg, oleg.size());


  cout<<"Your vector: ";
    for (int i = 0; i <newOleg.size() ; ++i) {
        cout<<newOleg[i];
    }


    return 0;
}
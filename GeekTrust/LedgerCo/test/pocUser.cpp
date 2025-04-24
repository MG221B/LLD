#include "user.h"
#include <iostream>
using namespace std;

int main()
{
  User* a = new User("Master");
  a->addLoan("ICICI", 10000, 4, 5);
  int remAmt=0, remTime =0;
  a->getDues("ICICI", 5, remAmt, remTime);
  cout<<"Paid - "<<remAmt<<" Time Left - "<<remTime<<endl;
  a->updateDues("ICICI", 1000, 5);
  remAmt =0;
  remTime = 0;
  a->getDues("ICICI", 6, remAmt, remTime);
  cout<<"Paid - "<<remAmt<<" Time Left - "<<remTime<<endl;
  return 0;
}

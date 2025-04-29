#include "person.h"
#include <iostream>
using namespace std;

int main()
{
  Person* person = Person::createRole("RIDER");
  Person* person2 = Person::createRole("DRIVER");
  person->init("R-110", 2,3);
  person2->init("D-120", 2,3);
  cout<<person->getId()<<endl;
  cout<<person2->getId()<<endl;
}

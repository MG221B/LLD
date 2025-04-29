#include "person.h"
#include <iostream>
#include "rider.h"
#include "driver.h"
using namespace std;


Person* Person::createRole(const string &role)
{
  if(role == "RIDER")
    return new Rider();
  else if(role == "DRIVER")
    return new Driver();
  else
    return nullptr;
}

int Person::init(string id,int x, int y)
{
  try
  {
    m_id = id;
    m_cords = {x,y};
  }
  catch(...)
  {
    cout<<"Unhandled Exception"<<endl;
  }
}

string Person::getId()
{
  return m_id;
}

pair<int, int> Person::getCords()
{
  return m_cords;
}

Person::~Person()
{
}

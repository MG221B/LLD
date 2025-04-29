#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

enum class Role
{
  DRIVER,
  RIDER
};

class Person
{
  protected:
    string m_id;
    pair<int, int> m_cords;
  public:
    static Person* createRole(const string &role);
    int init(string id, int x, int y);
    virtual ~Person();
    pair<int,int> getCords();
    string getId();
};
#endif

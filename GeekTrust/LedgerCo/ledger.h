#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "user.h"

using namespace std;

class Ledger
{
  private:
    map<string, User*> m_usersMap;
  public:
   Ledger();
   int decode(const string &path); 
};

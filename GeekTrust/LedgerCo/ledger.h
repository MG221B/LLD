#include <string>
#include <fstream>
#include "user.h"
#include "ledger.h"

using namespace std;

class Ledger
{
  private:
    map<string, User*> m_usersMap;
  public:
   Ledger();
   int decode(const string &path); 
};

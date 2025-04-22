#include <vector>
#include <sstream>
#include <iostream>
#include "user.h"
using namespace std;

class ExpenseManager
{
  private:
    map <string, User*> m_usersMap;
    int displayBalances(const string &userId);
    int expenseCriteria(const vector<string> &args);
  public:
    void decode(const string &command);
    int registerUser(User* u);
    int split(User* owner, map<string, double> splitAmountMap);

};

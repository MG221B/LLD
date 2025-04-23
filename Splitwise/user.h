#ifndef USER_H
#define USER_H
#include <string>
#include <map>
using namespace std;

class User
{
  private:
    string m_userId;
    string m_name;
    string m_email;
    string m_contact;
  public:
    map<string, int> userBalanceMap;

    User();
    User(const string &id, const string &n, const string &e, const string &c);
    string getId();
    string getName();
    void displayBalance();
    int updateBalanceMap(User* owner, double amt);
    int lendAmount(User *owner, double amt);
};
#endif

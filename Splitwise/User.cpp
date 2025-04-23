#include "user.h"
using namespace std;

User::User()
{
  m_userId = "";
  m_name = "";
  m_email = "";
  m_contact = "";
}

User::User(const string &id, const string &n, const string &e, const string &c)
{
  m_userId = id;
  m_name = n;
  m_email = e;
  m_contact = c;
}

string User::getId()
{
  return m_userId;
}

string User::getName()
{
  return m_name;
}

int User::updateBalanceMap(User* owner, double amt)
{
  userBalanceMap[owner->getName()]+=amt; 
}

int User::lendAmount(User* taker, double amt)
{
  userBalanceMap[taker->getName()]-=amt; 
}

/*
void User::displayBalance()
{
  for(auto &u: m_userBalanceMap)
  {
    if(u.second < 0)
    {
      string user = 
    }
  }
}*/

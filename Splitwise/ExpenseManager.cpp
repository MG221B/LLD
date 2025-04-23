#include "expenseManager.h"

int ExpenseManager::registerUser(User* u)
{
  m_usersMap[u->getId()] = u;
}

void ExpenseManager::decode(const string &command)
{
  stringstream cmd(command);
  string splitS = "";
  vector <string> args;

  while(getline(cmd, splitS, ' '))
  {
    args.push_back(splitS);
  }

  if(args[0] == "SHOW")
  {
    if(args.size() == 1)
      displayBalances("");
    else
      displayBalances(args[1]);
  }
  else if(args[0] == "EXPENSE")
  {
    User* owner = m_usersMap[args[1]];
    int mode = expenseCriteria(args);
      cout<<"Mode = "<< mode <<endl;
    int people = stoi(args[3]);
    map<string, double> splitAmountMap;

    if(mode == 1)
    {
      double amount = stoi(args[2])*1.0/people;
      for(int i=0; i<stoi(args[3]); i++)
      {
        splitAmountMap[args[4+i]] = amount;
      }
      split(owner, splitAmountMap);
    }
    else if(mode == 2)
    {
      double totalPercent = 0.0;
      for(int i=0;i<stoi(args[3]); i++)
      {
        string u = args[4+i];
        double percent = stod(args[5 + stod(args[3]) + i]);
        totalPercent+=percent;
        double amount = percent / 100.0*(stod(args[2]));
        splitAmountMap[u] = amount;
      }
      if(totalPercent != 100.0)
      {
        splitAmountMap.clear();
        cout<<"Invalid Transaction"<<endl;
        return;
      }
      split(owner, splitAmountMap);
    }
    else
    {
      for(int i=0;i<stoi(args[3]); i++)
      {
        string u = args[4+i];
        double amount = stoi(args[5 + stoi(args[3]) + i]);
        splitAmountMap[u] = amount;
      }
      split(owner, splitAmountMap);
    }
    splitAmountMap.clear();
  }
  else
  {
    return;
  }
}

int ExpenseManager::split(User *owner, map<string, double> userAmtMap)
{
  for(auto itr : userAmtMap)
  {
    User* i = m_usersMap[itr.first];
    if(i->getId() != owner->getId())
    {
      i->updateBalanceMap(owner, itr.second);
      owner->lendAmount(i, itr.second);
    }
  }
}

int ExpenseManager::expenseCriteria(const vector<string> &args)
{
  for(int i=0; i<args.size();i++)
  {
    if(args[i] == "EQUAL")
      return 1;
    else if(args[i] == "PERCENT")
      return 2;
    else if(args[i] == "EXACT")
      return 3;
  }
  return -1;
}

int ExpenseManager::displayBalances(const string &userId)
{
  if(userId == "")
  {
    bool isBal = false;
    for(auto u: m_usersMap)
    {
      User* user = u.second;
      if(!isBal && user->userBalanceMap.size()>0)
        isBal = true;

      //for(int i = 0; i < user.userBalanceMap.size(); i++)
      for(auto i : user->userBalanceMap)
      {
        if(i.second > 0)
        {
          cout<<user->getName()<<" owes " <<i.first << ": "<<i.second<<endl;
        }
        /*else if(i.second < 0)
        {
          cout<<i.first<<" owes " <<user->getName()<< ": "<<i.second<<endl;
        }*/
      }
    }
    if(!isBal)
      cout<<"No balances"<<endl;
  }
  else
  {
    User* user = m_usersMap[userId];
    if(!user->userBalanceMap.size() > 0)
    {
      cout<<"No balances"<<endl;
      return -1;
    }
    for(auto i:user->userBalanceMap)
    {
      if(i.second > 0)
      {
        cout<<user->getName()<<" owes " <<i.first << ": "<<i.second<<endl;
      }
      else if(i.second < 0)
      {
        cout<<i.first<<" owes " <<user->getName()<< ": "<<(i.second*-1)<<endl;
      }
    }
  }
}


#include "myPlayer.h"
using namespace std;

MyPlayer::MyPlayer()
{
  m_topupCost=0;
  m_startDate = "";
  m_topupCostMap["FOUR_DEVICE"] = 50;
  m_topupCostMap["TEN_DEVICE"] = 100;
}

int MyPlayer::decode(const string &path)
{
  ifstream file;
  try
  {
    file.open(path);

    if(!file.is_open())
    {
      cout<<"Error opening file!"<<endl;
    }
    string line = "";

    while(getline(file, line))
    {
      //cout<<line<<endl;
      stringstream command(line);
      string word = "";
      vector<string> args;
      while(getline(command, word, ' '))
      {
        args.push_back(word);
      }
      // TODO
      // Process Based on arguments Received
      if(args[0] == "START_SUBSCRIPTION")
      {
        if(validateDate(args[1]) == -1)
        {
          cout<<"Invalid Date"<<endl;
          return -1;
        }
        m_startDate = args[1];
      }
      else if(args[0] == "ADD_SUBSCRIPTION")
      {
        if(m_startDate == "")
        {
          cout<<"SUBSCRIPTIONS_NOT_FOUND"<<endl;
          return -1;
        }
        if(createSubscription(args[1], args[2]) == -1)
        {
          cout<<"ADD_SUBSCRIPTION_FAILED DUPLICATE CATEGORY"<<endl;
        }
      }
      else if(args[0] == "ADD_TOPUP")
      {
        if(m_streamerModeMap.size() <= 0)
        {
          cout<<"ADD_TOPUP_FAILED SUBSCRIPTIONS_NOT_FOUND"<<endl;
          continue;
        }
        if(m_topupCost < 0)
        {
          cout<<"ADD_TOPUP_FAILED DUPLICATE_TOPUP"<<endl;
          return -1;
        }
        m_topupCost = m_topupCostMap[args[1]] * stoi(args[2]);
      }
      else if(args[0] == "PRINT_RENEWAL_DETAILS")
      {
        int totCost = 0;
        if(m_streamerModeMap.size() <= 0)
        {
          cout<<"SUBSCRIPTIONS_NOT_FOUND"<<endl;
          continue;
        }

        for(auto &streams : m_streamerModeMap)
        {
          cout<<"RENEWAL_REMINDER "<<streams.second->getMode()<< " "<<streams.second->getRemindDate()<<endl;
          totCost+= streams.second->getCost();
        }
        totCost+= m_topupCost;
        cout<<"RENEWAL_AMOUNT "<<totCost<<endl;
      }
    }
    file.close();
    return 1;
  }
  catch(...)
  {
    cout<<"Unhandled Exception"<<endl;
  }
}

int MyPlayer::createSubscription(const string &mode, const string &subType)
{
  if(m_streamerModeMap.count(mode) > 1)
    return -1;
  Streamer* s;
  s->getStreamer(mode, subType, m_startDate, s);
  m_streamerModeMap[mode] = s;
}

int MyPlayer::validateDate(const string &date)
{
  stringstream dt(date);
  string val;
  vector<int> dateVec;
  while(getline(dt, val, '-'))
  {
    dateVec.push_back(stoi(val));
  }
  if(dateVec[0] > 31 || dateVec[0] < 1)
    return -1;
  if(dateVec[1] > 12 || dateVec[1] < 1)
    return -1;
  if(dateVec[0] == 31 && dateVec[1] == 2 || dateVec[1] == 4 || dateVec[1] == 6 || dateVec[1] == 9 || dateVec[1] == 11)
    return -1;
  if(dateVec[1] == 2)
  {
    if(dateVec[0] > 29)
      return false;
    if(dateVec[0] == 29 && (dateVec[2]%100)%4 != 0)
      return false;
  }
  return true;
    return -1;
}

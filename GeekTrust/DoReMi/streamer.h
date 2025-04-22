#ifndef STREAMER_H
#define STREAMER_H
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;

enum class MEMBERSHIP
{
  FREE,
  PERSONAL,
  PREMIUM
};

struct Tariff
{
  int rate;
  int months;
  Tariff()
  {
    rate =0;
    months =0;
  }
  Tariff(int r, int m)
  {
    rate = r;
    months = m;
  }
};

class Streamer
{
  protected:
    int m_cost;
    string m_remindDate;
    string m_endDate;
    //map<string, MEDIA> m_mediaMap;
    //map<string, MEMBERSHIP> m_membershipMap;
    string calculateEndDate(const string &startDate, const int &months);
    void init();

  public:
    Streamer();
    //Streamer* getStreamer(const string &mode, const string &subType, const string &startDate);
    int getStreamer(const string &mode, const string &subType, const string &startDate, Streamer*& s);
    string getRemindDate();
    int getCost();
    virtual string getMode() = 0;
};
#endif

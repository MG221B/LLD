#include <string>
#include <fstream>
#include "streamer.h"

using namespace std;

class MyPlayer
{
  private:
   string m_startDate; 
   int m_topupCost;
   map<string, Streamer*> m_streamerModeMap;
   map<string, int> m_topupCostMap;
   int validateDate(const string &date);
   int createSubscription(const string &mode, const string &subType);
  public:
   MyPlayer();
   int decode(const string &path);
};

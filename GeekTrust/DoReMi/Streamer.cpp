#include "streamer.h"
#include "musicStreamer.h"
#include "videoStreamer.h"
#include "podcastStreamer.h"

using namespace std;

Streamer::Streamer()
{
}
void Streamer::init()
{
}

int Streamer::getStreamer(const string &mode, const string &subType, const string &startDate, Streamer*& streamer)
{
  //init();
  if(mode == "MUSIC")
    streamer = new MusicStreamer(subType, startDate);
  else if(mode == "VIDEO")
    streamer = new VideoStreamer(subType, startDate);
  else if(mode == "PODCAST")
    streamer = new PodcastStreamer(subType, startDate);
  else
    streamer = nullptr;
  return 1;
}

string Streamer::calculateEndDate(const string &startDate, const int &months)
{
  stringstream date(startDate);
  string param;
  vector<int> params;
  while(getline(date, param, '-'))
  {
    params.push_back(stoi(param));
  }

  if(params[1] + months > 12)
  {
    m_endDate = to_string(params[0]) + "-"+to_string(params[1]+months - 12)+"-" + to_string(params[2]+1);
  }
  else
  {
    m_endDate = to_string(params[0]) + "-" + to_string(params[1]+months) + "-" + to_string(params[2]);
  }
  params.clear();
  stringstream date2(m_endDate);
  while(getline(date2, param, '-'))
  {
    params.push_back(stoi(param));
  }

  int remindDay = params[0] - 10;
  if(remindDay <= 0)
  {
    int remindMonth = params[1] - 1;
    string month = (remindMonth<10?("0"+to_string(remindMonth)):to_string(remindMonth));

    if(remindMonth == 4 || remindMonth == 6 || remindMonth == 11 || remindMonth == 9)
    {
      m_remindDate = to_string(30+ remindDay)+ "-" + month + "-" + to_string(params[2]);
    }
    else if(remindMonth == 2)
    {
      if((params[2]%100)%4 == 0)
        m_remindDate = to_string(29+ remindDay) + "-" + month + "-" + to_string(params[2]);
      else
        m_remindDate = to_string(28 + remindDay) + "-" + month + "-" + to_string(params[2]);
    }
    else
    {
      if(remindMonth == 0)
      {
        m_remindDate = to_string(31 + remindDay) + "-12-"+to_string(params[2]-1);
      }
      else
        m_remindDate = to_string(31 + remindDay) + "-" + month + "-" + to_string(params[2]);
    }
  }
  else
  {
    string day = (remindDay < 10 ? ("0"+to_string(remindDay)):to_string(remindDay));
    string month = (params[1] < 10 ? ("0"+to_string(params[1])):to_string(params[1]));
    m_remindDate = day + "-" + month +"-"+ to_string(params[2]);
  }
}

int Streamer::getCost()
{
  return m_cost;
}

string Streamer::getRemindDate()
{
  return m_remindDate;
}

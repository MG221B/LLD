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

  if(params[0] - 10 <= 0)
  {
    if((params[1] - 1) == 4 || (params[1] - 1) == 6 || (params[1] - 1) == 11 || (params[1] - 1) == 9)
    {
      m_remindDate = to_string(30+ params[0] - 10)+ "-" + to_string(params[1] - 1)+ "-" + to_string(params[2]);
    }
    else if(params[1] - 1 == 2)
    {
      if((params[2]%100)%4 == 0)
        m_remindDate = to_string(29+ params[0] - 10) + "-" + to_string(params[1] - 1) + "-" + to_string(params[2]);
      else
        m_remindDate = to_string(28 + params[0] - 10) + "-" + to_string(params[1] - 1) + "-" + to_string(params[2]);
    }
    else
    {
      if(params[1] - 1 == 0)
      {
        m_remindDate = to_string(31 + params[0] -10) + "-12-"+to_string(params[2]-1);
      }
      else
        m_remindDate = to_string(31 + params[0] - 10) + "-" + to_string(params[1]- 1) + "-" + to_string(params[2]);
    }
  }
  else
  {
    m_remindDate = to_string(params[0] - 10) +"-"+ to_string(params[1]) +"-"+ to_string(params[2]);
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

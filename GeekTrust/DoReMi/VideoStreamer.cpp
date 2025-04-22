#include "videoStreamer.h"
using namespace std;

VideoStreamer::VideoStreamer()
{
}

VideoStreamer::VideoStreamer(const string &membership, const string &startDate)
{
  init();
  m_cost+= m_tariffRate[membership]->rate;
  Streamer::calculateEndDate(startDate, m_tariffRate[membership]->months);
}

void VideoStreamer::init()
{
  m_cost = 0;
  m_tariffRate["FREE"] = new Tariff(0,1);
  m_tariffRate["PERSONAL"] = new Tariff(200,1);
  m_tariffRate["PREMIUM"] = new Tariff(500,3);
}

string VideoStreamer::getMode()
{
  return "VIDEO";
}

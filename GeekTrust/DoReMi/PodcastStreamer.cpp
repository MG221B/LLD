#include "podcastStreamer.h"
using namespace std;

PodcastStreamer::PodcastStreamer()
{
}

PodcastStreamer::PodcastStreamer(const string &membership, const string &startDate)
{
  init();
  m_cost+= m_tariffRate[membership]->rate;
  Streamer::calculateEndDate(startDate, m_tariffRate[membership]->months);
}

void PodcastStreamer::init()
{
  m_cost = 0;
  m_tariffRate["FREE"] = new Tariff(0,1);
  m_tariffRate["PERSONAL"] = new Tariff(100,1);
  m_tariffRate["PREMIUM"] = new Tariff(250,3);
}

string PodcastStreamer::getMode()
{
  return "PODCAST";
}

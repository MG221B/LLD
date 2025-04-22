#include "musicStreamer.h"
using namespace std;

MusicStreamer::MusicStreamer()
{
}

MusicStreamer::MusicStreamer(const string &membership, const string &startDate)
{
  init();
  m_cost += m_tariffRate[membership]->rate;
  Streamer::calculateEndDate(startDate, m_tariffRate[membership]->months);
}

void MusicStreamer::init()
{
  m_cost = 0;
  m_tariffRate["FREE"] = new Tariff(0,1);
  m_tariffRate["PERSONAL"] = new Tariff(100,1);
  m_tariffRate["PREMIUM"] = new Tariff(250,3);
}

string MusicStreamer::getMode()
{
  return "MUSIC";
}

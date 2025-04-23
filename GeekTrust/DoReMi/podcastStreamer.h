#include "streamer.h"

class PodcastStreamer : public Streamer
{
  public:
    PodcastStreamer();
    PodcastStreamer(const string &membership, const string &startDate);
    string getMode();
  private:
    map<string, Tariff*> m_tariffRate;
    void init();
};

#include "streamer.h"

class MusicStreamer : public Streamer
{
  public:
    MusicStreamer();
    MusicStreamer(const string &membership, const string &startDate);
    string getMode();
  private:
    map<string, Tariff*> m_tariffRate;
    void init();
};

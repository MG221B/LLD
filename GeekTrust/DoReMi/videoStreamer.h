#include "streamer.h"

class VideoStreamer : public Streamer
{
  public:
    VideoStreamer();
    VideoStreamer(const string &membership, const string &startDate);
    string getMode();
  private:
    map<string, Tariff*> m_tariffRate;
    void init();

};

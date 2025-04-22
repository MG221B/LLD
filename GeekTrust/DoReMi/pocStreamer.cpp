#include "streamer.h"
using namespace std;

int main()
{
  Streamer* s;
  s->getStreamer("MUSIC", "FREE", "01-01-2014", s);
  cout<<"Cost = "<< s->getCost() <<" Reminder - "<<s->getRemindDate()<<endl;
}

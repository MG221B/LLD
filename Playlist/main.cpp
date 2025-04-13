#include "playlistService.h"

using namespace std;

int main()
{
  PlaylistService playlist;
  while (true)
  {
    string command ="";
    getline(cin,command);

    playlist.resolve(command);
  }
}

#include <iostream>
#include <vector>
#include <unordered_map>
#include "video.h"
#include "userManager.h"

using namespace std;

struct Playlist
{
  string id;
  string name;
  vector<Video> videos;

  Playlist()
  {
    id = "";
    name = "";
  }
  Playlist(string name, string id)
  {
    this->id = id;
    this->name = name;
  }
};

class PlaylistService
{
  private:
    unordered_map<string, Playlist> m_idPlaylistMap;
    int m_counter = 0;
    string createPlaylist(const string &userId, const string &name);
    //int addVideos();
    //int removeVideos();
    //int removePlaylist();
    //int getPlaylist();
  public:
    int resolve(const string &command);
};

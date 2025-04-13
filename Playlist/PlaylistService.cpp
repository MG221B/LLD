#include "playlistService.h"

using namespace std;

string PlaylistService::createPlaylist(const string &userId, const string &name)
{
  m_counter++;
  string counter = to_string(m_counter);
  string playlistId = "PL" + userId + "_" + string(2 - counter.length(),'0') + counter;
  Playlist newP(name, playlistId);
  m_idPlaylistMap[playlistId] = newP;
  return playlistId;
}

int PlaylistService::resolve(const string &command)
{
  try
  {
    string action = command.substr(0,command.find("("));
    string meta = command.substr(command.find("("));

    if(action.find("create") != string :: npos)
    {
      string userId = meta.substr(9,4);
      string name = meta.substr(meta.find("\""));
      string id =  createPlaylist(userId, name);
      cout<<"Playlist Created successfully"<<endl;
      cout<<"Playlist Id: "<<id<<endl;
    }
    else if(action.find("add") != string::npos)
    {
      cout<<"Adding"<<endl;
      //editPlaylist();
    }
  }
  catch (...)
  {
  }
}

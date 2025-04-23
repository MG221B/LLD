#include "myPlayer.h"
using namespace std;

int main(int argc, char** argv)
{
  if(argc < 2)
  {
    cout<<"Usage -> ./<Bin> <InputFile> "<<endl;
    return 0;
  }
  string ipFilePath = argv[1];
  
  MyPlayer mPlayer;
  mPlayer.decode(ipFilePath);
  return 1;
}

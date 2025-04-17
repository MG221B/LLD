#include "parkingManager.h"

int main()
{
  ParkingManager parkingApp;
  cout<<"----Parking----"<<endl;
  while (true)
  {
    string readLine;
    getline(cin,readLine);
    int ret = parkingApp.decode(readLine);
    if(ret == -1)
    {
      return 1;
    }
  }
}

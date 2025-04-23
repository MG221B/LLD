#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "floor.h"

struct Parking
{
  string id;
  vector<Floor> floors;
  
  Parking(const string &pId, int floorCount, int slots)
  {
    id = pId;
    floors.resize(floorCount);
    for(auto &floor : floors)
    {
      floor.setSlots(slots);
    }
  }
};

class ParkingManager
{
  private:
  vector<Parking> m_parkingLots;
  string m_parkingId;
  int createNewParking(const string &pId, int floors, int slots);
  int displayCurrentParkingStatus(const string &action, string vehType);
  //addFloors(const string &id, int floors);
  int freeVehicle(const string &parkId);
  string parkVehicle(const string &vehType, const string &regNo, const string &color);

  public:
  int decode (const string &command);
};

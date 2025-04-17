#include "vehicle.h"
#include <vector>

struct Slot
{
  Vehicle* occupiedBy;
  VehicleType reservedFor;
  bool isFree;
  Slot()
  {
    isFree = true;
    occupiedBy = nullptr;
    reservedFor=VehicleType::CAR;
  }
};

class Floor
{
  int m_carCount;
  int m_bikeCount;
  int m_truckCount;
  int m_totalSlots;
  vector<Slot> slots;
  string getVehicleType(VehicleType type);
  public:
  int setSlots(const int &slot);
  int countFreeSlots(string vehicle);
  string displaySlots(Floor& floor, const string &vehicle, bool isFree);
  bool isVacant(const string &vehType);
  string park(Vehicle* &vehType, Floor &floor);
  int vacateSlot(Floor &f, const int &slot);
};

#include "vehicle.h"
class Truck : public Vehicle
{
  public:
    Truck(const string &regNo, const string &color);
    string getType(VehicleType type);
};

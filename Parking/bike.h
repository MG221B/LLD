#include "vehicle.h"
class Bike : public Vehicle
{
  public:
    Bike(const string &regNo, const string &color);
    string getType(VehicleType type);
};

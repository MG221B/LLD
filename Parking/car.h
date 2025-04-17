#include "vehicle.h"
class Car : public Vehicle
{
  public:
    Car(const string &regNo, const string &color);
    string getType(VehicleType type);
};

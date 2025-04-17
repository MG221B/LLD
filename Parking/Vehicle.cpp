#include "vehicle.h"
#include "bike.h"
#include "car.h"
#include "truck.h"
using namespace std;

Vehicle::Vehicle()
{
}

int Vehicle::registerVehicle(const string &regNo, const string &type, const string &color, Vehicle*& v)
{
  if(type == "CAR")
  {
    v = new Car(regNo, color);
  }
  if(type == "BIKE")
  {
    v = new Bike(regNo, color);
  }
  if(type == "TRUCK")
  {
    v = new Truck(regNo, color);
  }
  return 1;
}


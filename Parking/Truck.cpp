#include "truck.h"
using namespace std;

Truck::Truck(const string &regNo, const string &color)
{
  this->regNo = regNo;
  type = VehicleType::TRUCK;
  this->color = color;
}

string Truck::getType(VehicleType type)
{
  return "Truck";
}

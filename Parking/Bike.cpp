#include "bike.h"
using namespace std;

Bike::Bike(const string &regNo, const string &color)
{
  this->regNo = regNo;
  type = VehicleType::BIKE;
  this->color = color;
}

string Bike::getType(VehicleType type)
{
  return "Bike";
}

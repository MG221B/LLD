#include "car.h"
using namespace std;

Car::Car(const string &regNo, const string &color)
{
  this->regNo = regNo;
  type = VehicleType::CAR;
  this->color = color;
}

string Car::getType(VehicleType type)
{
  return "Car";
}

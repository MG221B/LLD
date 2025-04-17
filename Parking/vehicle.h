#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>

//#define ENUM_STRING(name) #name 
using namespace std;

enum class VehicleType
{
  CAR,
  BIKE,
  TRUCK
};

class Vehicle
{
  public:
    string regNo;
    string color;
    VehicleType type;
    Vehicle();
    int registerVehicle(const string &regNo,const string &type,const string &color, Vehicle*& v);
    virtual string getType(VehicleType type) = 0;
};
#endif

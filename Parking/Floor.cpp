#include "floor.h"

int Floor::setSlots(const int &slot)
{
  slots.resize(slot);
  slots[0].reservedFor = VehicleType::TRUCK;
  slots[1].reservedFor = VehicleType::BIKE;
  slots[2].reservedFor = VehicleType::BIKE;
  m_totalSlots = slot;
}

int Floor::countFreeSlots(string vehType)
{
  if(vehType=="CAR")
  {
    return m_totalSlots - m_carCount - 3;
  }
  else if(vehType=="BIKE")
  {
    return 2 - m_bikeCount;
  }
else if(vehType=="TRUCK")
  {
    return 1 - m_truckCount;
  }
}

bool Floor::isVacant(const string &vehType)
{
  if(countFreeSlots(vehType) == 0)
  {
    return false;
  }
  return true;
}

string Floor::park(Vehicle* &v, Floor &floor)
{
  string parkId="";
  for(int s=0; s<floor.slots.size(); s++)
  {
    if(floor.slots[s].reservedFor == v->type && floor.slots[s].isFree)
    {
      if(v->type == VehicleType::BIKE)
        m_bikeCount++;
      else if(v->type == VehicleType::CAR)
        m_carCount++;
      else
        m_truckCount++;
      floor.slots[s].occupiedBy = v;
      floor.slots[s].isFree = false;
      return to_string(s+1);
    }
  }
}

string Floor::getVehicleType(VehicleType type)
{
  if(type == VehicleType::BIKE)
    return "BIKE";
  else if(type == VehicleType::CAR)
    return "CAR";
  else if(type == VehicleType::TRUCK)
    return "TRUCK";
}

string Floor::displaySlots(Floor& floor, const string &vehType, bool isFree)
{
  string freeSlots="";
  for(int i=0;i<floor.slots.size();i++)
  {
    if(isFree)
    {
      if(getVehicleType(floor.slots[i].reservedFor) == vehType && floor.slots[i].isFree)
      {
        freeSlots+= to_string(i+1) + ",";
      }
    }
    else
    {
      if(getVehicleType(floor.slots[i].reservedFor) == vehType && !floor.slots[i].isFree)
        freeSlots+= to_string(i+1) + ",";
    }
  }
  return freeSlots.substr(0,freeSlots.size()-1);
}

int Floor::vacateSlot(Floor &f, const int &slot)
{
  if(slot > f.slots.size() || f.slots[slot - 1].isFree)
    return -1;
  if(f.slots[slot - 1].reservedFor == VehicleType::BIKE)
    m_bikeCount--;
  if(f.slots[slot - 1].reservedFor == VehicleType::CAR)
    m_carCount--;
  if(f.slots[slot - 1].reservedFor == VehicleType::TRUCK)
    m_truckCount--;

  Vehicle* v = f.slots[slot - 1].occupiedBy;
  cout<<"Unparked vehicle with Registration Number: "<<v->regNo<<" and Color: "<< v->color<<endl;

  delete f.slots[slot - 1].occupiedBy; // = nullptr;
  f.slots[slot - 1].isFree = true;
  return 1;
}

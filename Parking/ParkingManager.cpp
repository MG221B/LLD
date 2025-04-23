#include "parkingManager.h"
using namespace std;

int ParkingManager::decode(const string &command)
{
  stringstream cmd(command);
  vector<string> args;
  string word;
  while(getline(cmd, word, ' '))
  {
    args.push_back(word);
  }

  if(args[0] == "exit")
  {
    return -1;
  }
  else if(args[0].find("create") !=  string::npos)
  {
    if(createNewParking(args[1], stoi(args[2]), stoi(args[3])) == -1)
    {
      cout<<"No Parking"<<endl;
    }
  }
  else if(args[0] == "park_vehicle")
  {
    string parkId = parkVehicle(args[1], args[2], args[3]);
    if(parkId != "")
    {
      cout<<"Parked Vehicle. Ticket Id: "+parkId<<endl;
    }
    else
      cout<<"Parking Lot Full"<<endl;
  }
  else if(args[0] == "unpark_vehicle")
  {
    freeVehicle(args[1]);
  }
  else if(args[0] == "display")
  {
    displayCurrentParkingStatus(args[1], args[2]);
  }
}

int ParkingManager::freeVehicle(const string &parkId)
{
  size_t t1 = parkId.find("_");
  size_t t2 = parkId.rfind("_");
  int floor = stoi(parkId.substr(t1+1, t2-t1-1));
  int slot = stoi(parkId.substr(t2+1));
  if(floor > m_parkingLots[0].floors.size())
    cout<<"Invalid Ticket"<<endl;

  Floor& f = m_parkingLots[0].floors[floor-1];
  if(f.vacateSlot(f, slot) == -1)
  {
    cout<<"Invalid Ticket"<<endl;
  }
}

string ParkingManager::parkVehicle(const string &vehType, const string &regNo, const string &color)
{
  string ticketId = m_parkingId+"_";
  Vehicle* v;
  v->registerVehicle(regNo, vehType, color, v); // TODO
  Parking& p1 = m_parkingLots[0];

  for(int f1=0; f1 < p1.floors.size(); f1++)
  {
    if(p1.floors[f1].isVacant(vehType))
    {
      ticketId+= to_string(f1+1) + "_" + p1.floors[f1].park(v, p1.floors[f1]);
      return ticketId;
    }
  }
  return "";
}

int ParkingManager::createNewParking(const string &pId, int floors, int slots)
{
  Parking p1(pId, floors, slots);
  cout<<"Created parking lot with "<<floors<<" floors and "<<slots<<" slots per floor"<<endl;
  m_parkingLots.push_back(p1);
  m_parkingId = pId;
}

int ParkingManager::displayCurrentParkingStatus(const string &action, string vehType)
{
  vector<Floor>& floors = m_parkingLots[0].floors;
  if(action == "free_count")
  {
    for(int floor=0; floor<floors.size(); floor++)
    {
      int freeSlots = floors[floor].countFreeSlots(vehType);
      cout<<"No. of free slots for "<<vehType<<" on Floor "<< floor+1 <<": "<< freeSlots<<endl;
    }
  }
  else if(action == "free_slots")
  {
    for(int floor=0; floor<floors.size(); floor++)
    {
      string slots = floors[floor].displaySlots(floors[floor], vehType, true);
      cout<<"Free slots for "<< vehType <<" on Floor "<< floor+1 <<": "<< slots<<endl;
    }
  }
  else if(action == "occupied_slots")
  {
    for(int floor=0; floor<floors.size(); floor++)
    {
      string slots = floors[floor].displaySlots(floors[floor], vehType, false);
      cout<<"Occupied slots for "<< vehType <<" on Floor "<< floor+1 <<": "<< slots<<endl;
    }
  }
}

#include <string>
#include <fstream>
#include <queue>
#include <map>
#include <cmath>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "person.h"
#include "driver.h"
#include "rider.h"

using namespace std;

struct Ride
{
  string rideId;
  Driver* d;
  Rider* r;
  pair<int, int> startPos, endPos;
  double fare;
  Ride(const string &id, Driver* driver, Rider* rider)
  {
    rideId = id;
    d = driver;
    r = rider;
    startPos = rider->getCords();
    fare = 0.0;
  }
};

class RideHandler
{
  private:
    map<string, Rider*> m_riders;
    map<string, Driver*> m_drivers;
    map<string, Ride*> m_rides;
    map<string, vector<string>> m_riderDriversMap;
    int getAvailableRides(const string &riderId);
    int startRide(const string &rideId, const int &driverNum, const string &riderId);
    int stopRide(const string &rideId, const pair<int, int> endC, const int &time);
    int generateInvoice(const string &rideId);
    double calculateRideCost(double distance, int time);
    double calculateDistance(pair<int,int> ptA, pair<int, int> ptB);
  public:
    int decode(const string &path);
    RideHandler();
};

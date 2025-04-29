#include "rideHandler.h"

using namespace std;

RideHandler::RideHandler()
{
}

int RideHandler::decode(const string &path)
{
  ifstream file;
  try
  {
    file.open(path);

    if(!file.is_open())
    {
      cout<<"Error opening file!"<<endl;
    }
    string line = "";

    while(getline(file, line))
    {
      //cout<<line<<endl;
      stringstream command(line);
      string word = "";
      vector<string> args;
      while(getline(command, word, ' '))
      {
        args.push_back(word);
      }
      if(args[0].find("ADD_") != string::npos)
      {
        string role = args[0].substr(4);
        Person* newP = Person::createRole(role);
        if(newP != nullptr)
          newP->init(args[1], stoi(args[2]), stoi(args[3]));
        if(role == "RIDER")
        {
          m_riders[args[1]] = dynamic_cast<Rider*>(newP);
        }
        else
          m_drivers[args[1]] = dynamic_cast<Driver*>(newP);
      }
      else if(args[0] == "MATCH")
        getAvailableRides(args[1]);
      else if(args[0] == "START_RIDE")
        startRide(args[1], stoi(args[2]), args[3]);
      else if(args[0] == "STOP_RIDE")
      {
        pair<int, int> endCord = make_pair(stoi(args[2]), stoi(args[3]));
        stopRide(args[1], endCord, stoi(args[4]));
      }
      else if(args[0] == "BILL")
        generateInvoice(args[1]);
    }
    file.close();
    return 1;
  }
  catch(...)
  {
    cout<<"Unhandled Exception"<<endl;
  }
}

int RideHandler::generateInvoice(const string &rideId)
{
  Ride* ride = m_rides[rideId];
  cout<<"BILL "<<rideId<<" "<<ride->d->getId()<<" "<<fixed<<setprecision(2)<<ride->fare;
  cout<<"\n";
}

int RideHandler::startRide(const string &rideId, const int &driverNum, const string &riderId)
{
  vector<string> avalRides = m_riderDriversMap[riderId];
  Driver* d = m_drivers[avalRides[driverNum - 1]];
  Rider* r  = m_riders[riderId];
  Ride* newRide = new Ride(rideId, d, r);
  m_rides[rideId] = newRide;
  cout<<"Ride Started "<< rideId <<endl;
}

double RideHandler::calculateRideCost(double distance, int time)
{
  double netCost = 50.0;
  netCost+= 6.5*distance;
  netCost += 2*time;
  netCost += 0.2*netCost;
  return netCost;
}

double RideHandler::calculateDistance(pair<int,int> ptA, pair<int, int> ptB)
{
  return (sqrt(pow(ptA.first-ptB.first, 2) + pow(ptA.second-ptB.second, 2)));
}

int RideHandler::stopRide(const string &rideId, const pair<int, int> endC, const int &time)
{
  Ride* ride = m_rides[rideId];
  double distance = calculateDistance(ride->startPos, endC);
  double fare = calculateRideCost(distance, time);
  ride->endPos = endC;
  ride->fare = fare;
  cout<<"Ride Stopped "<<rideId<<endl;
}

struct compareDriver
{
  bool operator()(pair<string, double> a, pair<string, double> b)
  {
    return a.second > b.second;
  }
};

int RideHandler::getAvailableRides(const string &riderId)
{
  Rider* rider = m_riders[riderId];
  priority_queue<pair<string, double>, vector<pair<string,double>>, compareDriver> driverQ;
  for(auto itr : m_drivers)
  {
    Driver* driver = itr.second;
    double distance = calculateDistance(driver->getCords(), rider->getCords());
    if(distance <= 5.0)
    {
      driverQ.push({driver->getId(), distance});
    }
  }
  vector<string> avalRiders;
  cout<<"Drivers Matched "<<" ";
  while(!driverQ.empty() && avalRiders.size() < 5)
  {
    cout <<driverQ.top().first<<" ";
    avalRiders.push_back(driverQ.top().first);
    driverQ.pop();
  }
  m_riderDriversMap[riderId] = avalRiders;
  cout<<endl;
}

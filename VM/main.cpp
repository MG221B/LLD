#include "vendingMachine.h"

using namespace std;

int main()
{
  VendingMachine machine;
  while (true)
  {
    // Constants
    string command = "";

    cout<<"-- Vending Machine Active --"<<endl;
    getline(cin,command);

    machine.process(command);
  }
}

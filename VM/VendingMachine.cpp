#include "vendingMachine.h"

using namespace std;

VendingMachine::VendingMachine()
{
  init();
}

VendingMachine::~VendingMachine()
{
}

int VendingMachine::init()
{
}

void split(string command, vector<string> &args, char delimeter)
{
  stringstream strCommand(command);
  string input = "";

  while(getline(strCommand, input, delimeter))
  {
    args.push_back(input);
  }
  return;
}

int VendingMachine::process(const string command)
{
  vector<string> args;

  split(command, args, ' ');

  if(args[0] ==  "DISPLAY")
    m_products.showcase();
  else if(args[0] == "INSERT")
    m_wallet.credit(stoi(args[1]));
  else if(args[0] == "SELECT")
    processTransaction(args[1]);
  else if (args[0] == "CANCEL")
    abortTransaction();
  else
    cout<<"Invalid Command"<<endl;
}

int VendingMachine::processTransaction(string productCode)
{
  string buyProd = m_products.getAvailableProduct(productCode);
  if(buyProd != "")
  {
    cout<<"Dispensing product: "<<buyProd<<endl;
  }
  int prodPrice = m_products.getProductPrice(buyProd);
  cout<<"Product Price "<< prodPrice<<endl;
  m_wallet.debit(prodPrice);
  cout<<"Change returned: "<<m_wallet.getBalance()<<endl;
  m_products.updateProductQuantity(buyProd);
  m_wallet= Wallet();
}

void VendingMachine::abortTransaction()
{
  cout<<"Transaction Cancelled"<<endl;
  cout<<"Refunding Amount: "<<m_wallet.getBalance()<<" rupees"<<endl;
  m_wallet=Wallet();
  return;
}



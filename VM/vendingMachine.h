#include "wallet.h"
#include <sstream>
#include <iostream>
#include "productFactory.h"

using namespace std;

class VendingMachine
{
  private:
    Wallet m_wallet;
    ProductFactory m_products;
    int processTransaction(string productCode);
    void abortTransaction();
  public:
    VendingMachine();
    ~VendingMachine();
    int init();
    int process(const string command);
};

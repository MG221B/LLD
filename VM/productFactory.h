#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Product
{
  string productName;
  string productCode;
  int price;
  int quantity;

  Product()
  {
    productName ="";
    productCode ="";
    price = 0;
    quantity = 0;
  }
  Product(string name, string code, int p, int q)
  {
    productName =name;
    productCode =code;
    price = p;
    quantity = q;
  }
};

class ProductFactory
{
  private:
    vector<Product> m_productsList;
    int init();
  public:
    ProductFactory();
    ~ProductFactory();
    void showcase();
    string getAvailableProduct(const string &code);
    int getProductPrice(const string &name);
    void updateProductQuantity(const string name);
};

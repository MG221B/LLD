#include "productFactory.h"

using namespace std;

ProductFactory::ProductFactory()
{
  init();
}

ProductFactory::~ProductFactory()
{
}

int ProductFactory::init()
{
  Product p1("Chips", "A1", 50, 10);
  Product p2("Soda", "A2", 100, 5);
  Product p3("Candy", "B1", 65, 7);
  m_productsList.push_back(p1);
  m_productsList.push_back(p2);
  m_productsList.push_back(p3);
  return 0;
}

void ProductFactory::showcase()
{
  cout<<"Product Code\t|\tName\t|\tPrice\t|\tQuantity"<<endl;
  for(Product p:m_productsList)
  {
    cout<<p.productCode<<"\t|\t"<<p.productName<<"\t|\t"<<p.price<<"\t|\t"<<p.quantity<<endl;
  }
}

string ProductFactory::getAvailableProduct(const string &code)
{
  for(Product p:m_productsList)
  {
    if(p.productCode == code && p.quantity > 0)
        return p.productName;
 }
  return "";
}

int ProductFactory::getProductPrice(const string &name)
{
  for(Product p:m_productsList)
  {
    if(p.productName == name)
        return p.price;
 }
  return -1;
}

void ProductFactory::updateProductQuantity(const string name)
{
  for(Product &p : m_productsList)
  {
    if(p.productName == name)
    {
      p.quantity--;
      break;
    }
  }
  return;
}

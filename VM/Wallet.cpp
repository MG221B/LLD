#include "wallet.h"
#include <iostream>

using namespace std;

int Wallet::credit(const int &money)
{
  m_Balance+=money;
  cout<<"Balance - "<<m_Balance<<endl;
}

int Wallet::debit(const int &money)
{
  cout<<"Balance Before - "<<m_Balance<<endl;
  m_Balance-=money;
  cout<<"Balance After - "<<m_Balance<<endl;
}

int Wallet::getBalance()
{
  return m_Balance;
}

Wallet::Wallet()
{
  m_Balance = 0;
}

Wallet::~Wallet()
{
}

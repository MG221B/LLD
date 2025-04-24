#include "user.h"
//#include <iostream>
using namespace std;

User::User(const string &name)
{
  m_name = name;
}

int User::addLoan(const string &bankName, const double &p, const double &r, const int &t)
{
  double interest = (p*r*t/100.0);
  int months = t*12;
  double loanAmt = p+interest;
  double emi = ceil((loanAmt)/months);
  Loan* newLoan = new Loan(bankName, emi, loanAmt);
  m_bankLoanMap[bankName] = newLoan;
  m_paymentVec.resize(months,emi);
}

int User::getDues(const string bank, const int months, int &paidAmt, int &remTime)
{
  Loan* loanPtr = m_bankLoanMap[bank];
  for(int i=0;i<months;i++)
  {
    //cout<<"EMI - "<<m_paymentVec[i]<<endl;
    paidAmt+=m_paymentVec[i];
  }
  remTime = ceil((loanPtr->loanAmount - paidAmt) / loanPtr->emiAmt);
  m_paymentVec.resize(remTime);

   return 1;
}

int User::updateDues(const string bank, const int fixPmt,const int time)
{
  Loan* loanPtr = m_bankLoanMap[bank];
  m_paymentVec[time-1]+= fixPmt;
  //m_paymentVec.resize()
}

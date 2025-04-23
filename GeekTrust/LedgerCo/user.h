#include <cmath>
using namespace std;

struct Loan
{
  string bank;
  double emiAmt;
  int paidAmt;
  double loanAmount;
  Loan(string bankName, double emi, double amount)
  {
    bank = bankName;
    emiAmt = emi;
    loanAmout = amount;
    paidAmt = 0;
  }
};

class User
{
  private:
    string m_name;
    map<string, Loan*> m_bankLoanMap;
    vector <int> m_paymentVec;
    //vector<Loan*> m_loans;
  public:
    User(const string &name);
    int addLoan(const string &bankName, const double &p, const double &r, const int &t);
    int getDues(const string bank, const int months, int &remAmt, int &remTime);
    int updateDues(const string bank, const int Amt,const int time);
}

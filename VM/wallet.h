
using namespace std;

class Wallet
{
  private:
    int m_Balance;
  public:
    Wallet();
    ~Wallet();
    int credit(const int &money);
    int debit (const int &money);
    int getBalance();
};

#include "ledger.h"
using namespace std;

Ledger::Ledger()
{
}

int Ledger::decode(const string &path)
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
      if(args[0] == "LOAN")
      {
        if(m_usersMap.count(args[2]) >= 1)
        {
          m_usersMap[args[2]]->addLoan(args[1], stod(args[3]), stod(args[4]), stoi(args[5]));
        }
        else
        {
          User* newUser = new User(args[2]);
          newUser->addLoan(args[1], stod(args[3]), stod(args[5]), stoi(args[4]));
          m_usersMap[args[2]] = newUser;
        }
      }
      else if(args[0] == "BALANCE")
      {
        string bank = args[1];
        User* user = m_usersMap[args[2]];
        int paidAmt =0, remTime =0;
        user->getDues(bank, stoi(args[3]), paidAmt, remTime);
        cout<<bank<<" "<<args[2]<<" "<<paidAmt<<" "<<remTime<<endl;
      }
      else if(args[0] == "PAYMENT")
      {
        string bank = args[1];
        User* user = m_usersMap[args[2]];
        user->updateDues(bank, stoi(args[3]), stoi(args[4]));
      }
    }
    file.close();
    return 1;
  }
  catch(...)
  {
    cout<<"Unhandled Exception"<<endl;
  }
}

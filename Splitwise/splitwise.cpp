#include "user.h"
#include "expenseManager.h"
using namespace std;

int main()
{
  User* u1 = new User("u1", "User 1", "abc@gmail.com", "9299292");
  User* u2 = new User("u2", "User 2", "abd@gmail.com", "92992924");
  User* u3 = new User("u3", "User 3", "abe@gmail.com", "92992923");
  User* u4 = new User("u4", "User 4", "abf@gmail.com", "92992922");
  User* u5 = new User("u5", "User 5", "abg@gmail.com", "92992921");

  ExpenseManager app;
  app.registerUser(u1);
  app.registerUser(u2);
  app.registerUser(u3);
  app.registerUser(u4);
  app.registerUser(u5);

  while (true)
  {
    string command;
    getline(cin,command);
    app.decode(command);
  }
}

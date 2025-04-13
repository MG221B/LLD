struct User
{
  int id;
  User(int id)
  {
    this->id=id;
  }
};

class UserManager
{
  public:
    int addUser(string userId);
};

#include "ledger.h"
using namespace std;

int main(int argc, char** argv)
{
  if(argc < 2)
  {
    cout<<"Usage -> <Bin> <InputFile> "<<endl;
    return 0;
  }
  string ipFilePath = argv[1];
  
  Ledger l1;
  l1.decode(ipFilePath);
  return 1;
}

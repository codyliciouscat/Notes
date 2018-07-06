#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
  if(argc == 1)
    cout << "\033[1;31mERROR:\033[0m missing argument. HINT: Try file name" << endl;
  else if(argc > 2)
    cout << "\033[1;31mERROR:\033[0m invalid argument. HINT: encrypt <file_name>" << endl;
  

#include <string>
#include <iostream>

using namespace std;

bool yes_no_prompt(string prompt)
{
  cout << prompt << endl;
  string input;
  cin >> input;
        
  if ((input == "y") || (input == "Y"))
  {
    return true;
  }
}

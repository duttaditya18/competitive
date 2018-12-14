#include <iostream>
#include <string>

using namespace std;
int main()
{
  string str;
  cin >> str;

  // false = excel, true = weird
  bool style = false;

  for (int i = 0; i < str.size(); i++)
  {
    // checks if i'th character is C and is a number and i != 0 (weird style)
    if (i != 0 && (str[i - 1] >= 48 && str[i - 1] <= 57) && str[i] == 'C')
    {
      style = true;
    }
  }

  // Convert to Excel
  if (style)
  {
    string rStr;
    string cStr;
    for (int i = 1; i < str.size() && str[i] != 'C'; i++)
    {
      rStr.push_back(str[i]);
    }
    for (int i = (str.size() - 1); i > 0 && str[i] != 'C'; i--)
    {
      cStr = str[i] + cStr;
    }
    int r = stoi(rStr);
    int c = stoi(cStr);
  }
  return 0;
}

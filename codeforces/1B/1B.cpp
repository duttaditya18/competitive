#include <iostream>
#include <string>
#include <cctype>

using namespace std;
int main()
{
  int n;
  cin >> n;
  for (int f = 0; f < n; f++)
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

      int c = stoi(cStr);

      cStr.clear();

      string ax;
      int m;

      while (c > 0)
      {
        m = (c - 1) % 26;
        ax = (char)(65 + m) + ax;
        c = (int)((c - m) / 26);
      }

      string printer = ax + rStr;
      cout << printer << endl;
    }
    else
    {
      string rStr;
      string cStr;

      int c = 0;
      for (int i = 0; (i < str.size()) && isalpha(str[i]); i++)
      {
        cStr.push_back(str[i]);
      }
      for (int i = (str.size() - 1); i > 0 && isdigit(str[i]); i--)
      {
        rStr = str[i] + rStr;
      }

      for (int i = 0; i < cStr.size(); i++)
      {
        c *= 26;
        c += (cStr[i] - 'A' + 1);
      }

      string printer = "R" + rStr + "C" + to_string(c);
      cout << printer << endl;
    }
  }
  return 0;
}

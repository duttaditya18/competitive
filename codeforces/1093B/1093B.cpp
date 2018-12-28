#include <iostream>

using namespace std;

bool palindrome(string);
bool possible(string);

int main()
{
  int t;
  cin >> t;

  for (int j = 0; j < t; j++)
  {
    string s;
    cin >> s;

    if (palindrome(s))
    {
      if (!possible(s))
      {
        cout << -1 << endl;
      }
      else
      {
        for (int i = 1; i < s.length(); i++)
        {
          if (s[i] != s[i - 1])
          {
            char temp = s[i];
            s[i] = s[i - 1];
            s[i - 1] = temp;
            break;
          }
        }

        cout << s << endl;
      }
    }
    else
    {
      cout << s << endl;
    }
  }

  return 0;
}

bool palindrome(string s)
{
  int n = s.length();
  for (int i = 0; i < n; i++)
  {
    if (s[i] != s[n - i - 1])
    {
      return false;
    }
  }
  return true;
}

bool possible(string s)
{
  for (int i = 1; i < s.length(); i++)
    if (s[i] != s[0])
      return true;

  return false;
}
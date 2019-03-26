// TODO

#include <iostream>

using namespace std;

int main(void)
{
  string n;
  cin >> n;
  int size = n.size();
  bool d = false;
  for (int i = 0; i < size && !d; i++)
  {
    for (int j = 0; j < size && !d; j++)
    {
      string x = n;
      x.erase(i, j);
      if (x.length() > 3)
      {
        if (stoi(x.substr(x.length() - 3)) % 8 == 0)
        {
          d = true;
          cout << "YES" << endl
               << x;
        }
      }
      else
      {
        if (stoi(x) % 8 == 0)
        {
          d = true;
          cout << "YES" << endl
               << x;
        }
      }
    }
  }

  if (!d)
  {
    cout << "NO";
  }

  return 0;
}
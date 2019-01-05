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
    for (int j = 1; j < size - i && !d; j++)
    {
      string x = n;
      x.erase(i, j);
      if (stoi(x) % 8 == 0)
      {
        d = true;
        cout << "YES" << endl
             << x;
      }
    }
  }

  if (!d)
  {
    cout << "NO";
  }

  return 0;
}
#include <iostream>

using namespace std;

int main()
{
  string t, a[5];
  cin >> t;
  bool x = false;
  for (int i = 0; i < 5 && !x; i++)
  {
    cin >> a[i];
    if (t[0] == a[i][0] || t[1] == a[i][1])
    {
      x = true;
    }
  }
  cout << (x ? "YES" : "NO");
  return 0;
}

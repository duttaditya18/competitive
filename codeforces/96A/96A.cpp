#include <iostream>
#include <string>

using namespace std;
int main()
{
  string a;
  cin >> a;
  int n = a.length();
  int c = 1;
  bool x = false;
  for (int i = 0; i < n - 1; i++)
  {
    if (a[i] == a[i + 1])
    {
      c++;
    }
    else
    {
      c = 1;
    }
    if (c >= 7)
    {
      x = true;
    }
  }
  cout << (x ? "YES" : "NO");
  return 0;
}

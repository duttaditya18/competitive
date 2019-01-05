#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
  int n;
  cin >> n;
  int f[n];
  for (int i = 1; i <= n; i++)
  {
    cin >> f[i];
  }

  bool x = false;
  for (int i = 1; i <= n; i++)
  {
    if (f[f[f[i]]] == i)
    {
      x = true;
    }
  }

  cout << (x ? "YES" : "NO");
  return 0;
}

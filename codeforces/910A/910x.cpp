#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
  int n, d, c = 0;
  cin >> n >> d;
  char a[n];
  cin >> a;

  int l = 0;
  int r;
  while (l < n)
  {
    r = l + d;
    if (r >= n - 1)
    {
      c++;
      break;
    }
    while (a[r] != '1')
    {
      r--;
      if (r == l)
      {
        cout << -1 << endl;
        return 0;
      }
    }
    l = r;
    c++;
  }
  cout << c << endl;
  return 0;
}
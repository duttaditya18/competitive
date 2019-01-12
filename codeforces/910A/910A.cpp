#include <iostream>
#include <cstdio>

int n, d, c = 0;
using namespace std;

int calc(char a[], int l, int r)
{
  int ren;
  cout << "doing things from " << l << " to " << r << endl;
  cout << "c is : " << c << endl;
  for (int i = r; i > l; i--)
  {
    if ((r >= n - 1))
    {
      continue;
    }
    if (a[i] == '1')
    {
      c++;
      ren = calc(a, r + 1, r + d);
      break;
    }
  }
  return ren;
}

int main(void)
{
  cin >> n >> d;
  char a[n];
  cin >> a;
  cout << calc(a, 0, (d - 1));
  return 0;
}
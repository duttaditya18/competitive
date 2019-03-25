#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int n;
  cin >> n;
  int a[n];
  int c = 0;
  int m = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (int i = 0; i < 2 * n; i++)
  {
    if (a[i % n] == 1)
    {
      c++;
      m = max(m, c);
    }
    else
    {
      c = 0;
    }
  }
  cout << m;
}
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int a[n];

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  sort(a, a + n);

  int c = 0;
  for (int i = 0; i < n / 2; i++)
  {
    c += abs(a[i * 2] - a[i * 2 + 1]);
  }

  cout << c;
  return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
  long long int n;
  cin >> n;

  long long int b;
  long long int a[n];
  for (int i = 0; i < n / 2; i++)
  {
    cin >> b;
    if (i == 0)
    {
      a[i] = 0;
      a[n - 1] = b;
    }
    else
    {
      a[i] = max(a[i - 1], min(a[n - i], b - a[n - i]));
      a[n - i - 1] = b - a[i];
      // cout << " | i: " << i << " | b: " << b << " | a[i - 1]: " << a[i - 1] << " | a[n - i]: " << a[n - i] << " | b - a[n - i]: " << b - a[n - i] << " | a[i]: " << a[i] << " | a[n - i - 1]: " << a[n - i - 1] << endl;
    }
  }

  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  return 0;
}
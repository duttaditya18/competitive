#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;

  int a[k], s = k;
  fill(a, a + k, 1);

  for (int i = k - 1; i >= 0; i--)
  {
    // cout << "i: " << i << " s: " << s << " a[i]: " << a[i] << " n: " << n << endl;
    while (s + a[i] <= n)
    {
      s += a[i];
      a[i] *= 2;
    }
    // cout << "i: " << i << " s: " << s << " a[i]: " << a[i] << " n: " << n << endl;
  }

  if (s != n)
    cout << "NO" << endl;
  else
  {
    cout << "YES" << endl;
    for (int i = 0; i < k; i++)
      cout << a[i] << " ";
  }
}

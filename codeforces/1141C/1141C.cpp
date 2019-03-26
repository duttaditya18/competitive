#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  long long n;
  long long sum = 0;
  long long minval = 0;
  cin >> n;

  long long q[n] = {0}, p[n] = {0}, r[n + 1] = {0};

  for (int i = 0; i < n - 1; i++)
  {
    cin >> q[i];
    sum += q[i];
    p[i + 1] = sum;
    minval = min(minval, p[i + 1]);
  }

  for (int i = 0; i < n; i++)
  {
    p[i] = p[i] + 1 - minval;
    if (p[i] > n || p[i] < 0 || r[p[i]] > 0)
    {
      cout << -1;
      return 0;
    }
    r[p[i]]++;
  }

  for (int i = 0; i < n; i++)
  {
    cout << p[i] << " ";
  }
}
#include <iostream>
#include <vector>

using namespace std;

int n = 100000000;

// all are intialized at true
vector<int> is_prime(n + 1, true);

void sieve(void)
{
  for (int i = 2; i * i <= n; i++)
  {
    if (is_prime[i])
    {
      for (int j = i * i; j <= n; j += i)
      {
        is_prime[j] = false;
      }
    }
  }
}

int main(void)
{
  sieve();
  int t;
  cin >> t;
  while (t--)
  {
    int m, n;
    cin >> m >> n;
    for (int i = m; i <= n; i++)
    {
      if (is_prime[i] && i != 0 && i != 1)
        cout << i << endl;
    }
    cout << endl;
  }
  return 0;
}

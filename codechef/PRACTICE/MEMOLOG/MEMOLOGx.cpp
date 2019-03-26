#include <bits/stdc++.h>

using namespace std;

#define MAX 1000007
int prime[MAX], ans[MAX];

// Sieve of Eratosthenes Technique
void sieve()
{
  // fills all true primes
  fill(prime, prime + MAX, 1);

  for (int p = 2; p * p <= MAX; p++)
  {
    // if it is a prime
    if (prime[p])
    {
      for (int i = p * p; i <= MAX; i += p)
      {
        prime[i] = 0;
      }
    }
  }

  // prime counter
  int c = 0;

  // fills all the answer sets
  for (int i = 2; i < MAX; i++)
  {
    if (prime[i])
    {
      c++;
    }
    // sets prime at each step
    ans[i] = c;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  sieve();
  int q, n;
  cin >> q;
  while (q--)
  {
    cin >> n;
    cout << ans[n] << endl;
  }
  return 0;
}
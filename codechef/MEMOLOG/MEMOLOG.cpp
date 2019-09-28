#include <iostream>

using namespace std;

bool isPrime(int);

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int q;
  cin >> q;

  for (int k = 0; k < q; k++)
  {
    int n;
    cin >> n;

    int c = 0;
    for (int i = 3; i <= n; i++)
    {
      if (isPrime(i))
      {
        c++;
      }
    }

    cout << c + 1 << endl;
  }
}

bool isPrime(int n)
{
  if (n <= 3)
    return n > 1;

  else if ((n % 2 == 0) || (n % 3 == 0))
    return false;

  int i = 5;
  while (i * i <= n)
  {
    if ((n % i == 0) || (n % (i + 2) == 0))
    {
      return false;
    }
    i = i + 6;
  }
  return true;
}

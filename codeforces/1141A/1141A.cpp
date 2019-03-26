#include <iostream>

using namespace std;

int main(void)
{
  int a, b, d = 0;
  cin >> a >> b;

  if (b % a)
  {
    cout << -1;
    return 0;
  }
  else
  {
    b /= a;
    while (!(b % 2))
    {
      b /= 2, d++;
    }
    while (!(b % 3))
    {
      b /= 3, d++;
    }
    if (b != 1)
    {
      cout << -1;
      return 0;
    }
    cout << d;
  }
  return 0;
}
#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
  long long a, b;
  int x = 1;
  cin >> a >> b;

  if (b - a >= 10)
  {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i <= b - a; i++)
  {
    x = (((a + i) % 10) * x) % 10;
    if (x == 0)
    {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << x << endl;
  return 0;
}
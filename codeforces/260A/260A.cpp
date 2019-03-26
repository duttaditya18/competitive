#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  int a, b, n;
  cin >> a >> b >> n;

  for (int i = 0; i <= 9; i++)
  {
    if (((a * 10) + i) % b == 0)
    {
      cout << a << i;
      for (int j = 2; j <= n; j++)
        cout << 0;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
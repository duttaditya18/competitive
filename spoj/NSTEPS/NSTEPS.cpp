#include <iostream>

using namespace std;

int main(void)
{
  int n, x, y;
  cin >> n;
  while (n--)
  {
    cin >> x >> y;
    if (x == y)
      if (x % 2)
        cout << (x * 2 - 1);
      else
        cout << (x * 2);
    else if (x - y == 2)
      if (x % 2)
        cout << (x + y - 1);
      else
        cout << (x + y);
    else
      cout << "No Number";
    cout << endl;
  }
  return 0;
}

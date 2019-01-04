#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int n;
  cin >> n;
  cout << fixed << (int)(pow(3, 3 * n) - pow(7, n));
  return 0;
}

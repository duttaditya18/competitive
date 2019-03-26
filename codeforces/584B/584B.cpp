#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  unsigned long long n;
  cin >> n;
  cout << (long long)(pow(3, 3 * n) - pow(7, n)) % 1000000007;
  return 0;
}

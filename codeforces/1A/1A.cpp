#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  double n, m, a;
  cin >> n >> m >> a;
  cout << fixed << (long long)ceil(m / a) * (long long)ceil(n / a);
  return 0;
}
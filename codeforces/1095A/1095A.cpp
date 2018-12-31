#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
  int n;
  cin >> n;

  string t;
  cin >> t;

  int x = 0;

  for (int i = 1; i <= n && x < n; i++)
  {
    cout << t[x];
    x = i * (i + 3) / 2;
  }
  return 0;
}

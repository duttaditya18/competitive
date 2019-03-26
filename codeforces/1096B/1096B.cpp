#include <iostream>

using namespace std;

int main()
{
  int n;
  string s;
  cin >> n >> s;

  int lc = 1;
  int rc = 1;

  for (int i = 1; i < n; i++)
    if (s[0] == s[i])
      lc++;
    else
      break;

  for (int i = n - 2; i > 0; i--)
    if (s[n - 1] == s[i])
      rc++;
    else
      break;

  if (s[0] == s[n - 1])
  {
    cout << ((lc + 1) * 1ll * (rc + 1)) % 998244353;
  }
  else if (s[0] != s[n - 1])
  {
    cout << (lc + rc + 1) % 998244353;
  }
  return 0;
}

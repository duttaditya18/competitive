#include <iostream>

using namespace std;

#define MAX 100005
int a[MAX], l = 0, s = 1e9, t[MAX], b[MAX], ans[MAX];

int main(void)
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    b[i] = n - a[i];
    t[b[i]]++;
  }

  for (int i = 1; i <= n; i++)
  {
    if (t[b[i]] % b[i] != 0)
    {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  cout << "Possible" << endl;
  int cunt = 0;
  for (int i = 1; i <= n; i++)
  {
    if (t[b[i]] % b[i] == 0)
    {
      ans[b[i]] = ++cunt;
    }
    t[b[i]]--;
    cout << ans[b[i]] << " ";
  }
  cout << endl;

  return 0;
}

#include <iostream>

using namespace std;

int a[16], n;
bool flag = false;

void search(int x, int sum)
{
  // cout << "x: " << x << " sum: " << sum << endl;
  if (x == n)
  {
    if (!(sum % 360))
      flag = true;
    return;
  }
  search(x + 1, sum + a[x]);
  search(x + 1, sum - a[x]);
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  search(0, 0);

  cout << (flag ? "YES" : "NO");

  return 0;
}
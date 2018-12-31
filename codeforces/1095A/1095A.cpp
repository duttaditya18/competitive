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
  int i = 0;

  while (i < n)
  {
    cout << t[i];
    x++;
    i += x + 1;
  }
  return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
  int n, m;
  cin >> n >> m;

  char x[n][m];

  int ax = 116;
  int ay = 116;
  int bx = -116;
  bool d = true;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> x[i][j];
    }
  }

  for (int i = 0; i < n && d; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (x[i][j] == 'B')
      {
        d = false;
        ax = min(j, ax);
        ay = i;
        bx = max(j, bx);
      }
    }
  }
  cout << ay + 1 + (bx - ax) / 2 << " ";
  cout << (ax + bx) / 2 + 1;
}

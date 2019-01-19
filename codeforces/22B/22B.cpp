#include <bits/stdc++.h>

using namespace std;

int n, m, far[25][25];
char grid[25][25];

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> grid[n][m];
}
#include <algorithm>
#include <iostream>

using namespace std;

int n, m, out = 0;
// this somehow initialises everything to 0
int dp[27][27] = {};
char grid[27][27];

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cin >> grid[i][j];
      // calc how many 1's are there on left and up and includes iteself. think about sets sorta
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (grid[i][j] == '1');
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      for (int k = i; k <= n; k++)
      {
        for (int l = j; l <= m; l++)
        {
          // see supersonic nb last pages
          // basically it calculates if there are any zeroes in a given area. think about sets
          if (dp[i - 1][l] + dp[k][j - 1] - dp[i - 1][j - 1] == dp[k][l])
            out = max(out, 2 * ((k - i + 1) + (l - j + 1)));
        }
      }
    }
  }
  cout << out;
}
#include <bits/stdc++.h>

using namespace std;
#define INT_MIN -9999999999

long long dp[101][26][101] = {};

signed main(void)
{
    string s; cin >> s;
    int n = s.size();

    int a[n + 1] = {};
    for(int i = 1; i <= n; i++) a[i] = int(s[i - 1] - 'a');

    int m; cin >> m;
    int q; cin >> q;

    char x, y; int z;
    int cost[26][26] = {};

    for(int i = 0; i < q; i++)
    {
        cin >> x >> y >> z;
        x = x - 'a'; y = y - 'a';
        cost[x][y] = z;
    }

    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 26; j++)
            for(int k = 0; k <= m; k++)
                dp[i][j][k] = INT_MIN;


    dp[1][a[1]][0] = 0;

    for(int j = 0; j < 26; j++)
    {
        if(j == a[1]) continue;
        dp[1][j][1] = 0;
    }

    long long ans = INT_MIN;

    for(int i = 2; i <= n; i++)
    {
        for(int k = 0; k <= min(i, m); k++)
        {
            for(int j = 0; j < 26; j++)
            {
                dp[i][j][k] = INT_MIN;
                for(int l = 0; l < 26; l++)
                {
                    // Number of changes = 0
                    if(k == 0)
                    {
                        if(j == a[i])
                        {
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][l][k] + cost[l][j]);
                        }
                    }
                    else
                    {
                        if(j == a[i])
                        {
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][l][k] + cost[l][j]);
                        }
                        else
                        {
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][l][k - 1] + cost[l][j]);
                        }
                    }
                }
                if(i == n) ans = max(ans, dp[i][j][k]);
                // cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
            }
        }
    }

    cout << ans << endl;
}

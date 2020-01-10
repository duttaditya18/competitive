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
        x -= 'a'; y -= 'a';
        cost[x][y] = z;
    }

    for(int j = 0; j < 26; j++)
    {
        for(int k = 0; k <= m; k++)
        {
            dp[1][j][k] = INT_MIN;
            if((j != a[1] && k == 1) || (j == a[1] && k == 0)) dp[1][j][k] = 0;
        }
    }

    long long ans = INT_MIN;

    for(int i = 2; i <= n; i++)
    {
        for(int k = 0; k <= m; k++)
        {
            for(int j = 0; j < 26; j++)
            {
                dp[i][j][k] = INT_MIN;
                for(int l = 0; l < 26; l++)
                {
                    if(j == a[i])
                    {
                        if(dp[i - 1][l][k] != INT_MIN)
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][l][k] + cost[l][j]);
                    }
                    else if(k != 0)
                    {
                        if(dp[i - 1][l][k - 1] != INT_MIN)
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][l][k - 1] + cost[l][j]);
                    }
                }
                if(i == n) ans = max(ans, dp[i][j][k]);
                // cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
            }
        }
    }

    cout << ans << endl;
}

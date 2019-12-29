#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m, k; cin >> n >> m >> k;

    int c[n + 1] = {};
    for(int i = 1; i <= n; i++) cin >> c[i];

    long long p[n + 1][m + 1] = {};
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> p[i][j];

    // for(int i = 1; i <= n; i++) cout << c[i] << " "; cout << endl;
    // for(int i = 1; i <= n; i++) { for(int j = 1; j <= m; j++) cout << p[i][j] << " "; cout << endl; }

    long long dp[n + 1][k + 1][m + 1] = {};

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            for(int k = 1; k <= m; k++)
            {
                dp[i][j][k] = LLONG_MAX;
            }
        }
    }

    if(c[1] == 0)
    {
        for(int i = 1; i <= m; i++)
            dp[1][1][i] = p[1][i];
    }
    else
    {
        dp[1][1][c[1]] = 0;
    }

    for(int i = 2; i <= n; i++)
    {
        if(c[i] == 0)
        {
            // uncolored
            for(int j = 1; j <= k; j++)
            {
                for(int f = 1; f <= m; f++)
                {
                    long long mi = LLONG_MAX;
                    if(dp[i - 1][j][f] != LLONG_MAX) mi = dp[i - 1][j][f] + p[i][f];
                    for(int g = 1; g <= m; g++)
                    {
                        if(g == f) continue;
                        if(dp[i - 1][j - 1][g] != LLONG_MAX) mi = min(mi, dp[i - 1][j - 1][g] + p[i][f]);
                    }
                    dp[i][j][f] = mi;
                }
            }
        }
        else
        {
            // colored
            for(int j = 1; j <= k; j++)
            {
                for(int f = 1; f <= m; f++)
                {
                    if(f != c[i])
                    {
                        dp[i][j][f] = LLONG_MAX;
                        continue;
                    }
                    long long mi = LLONG_MAX;
                    if(dp[i - 1][j][f] != LLONG_MAX) mi = dp[i - 1][j][f];
                    for(int g = 1; g <= m; g++)
                    {
                        if(g == f) continue;
                        if(dp[i  - 1][j - 1][g] != LLONG_MAX) mi = min(mi, dp[i - 1][j - 1][g]);
                    }
                    dp[i][j][f] = mi;
                }
            }
        }
    }

    /*cout << endl << endl;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            for(int g = 1; g <= m; g++)
            {
                cout << dp[i][j][g] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }*/

    if(c[n] == 0)
    {
        long long ans = LLONG_MAX;
        for(int i = 1; i <= m; i++)
        {
            ans = min(ans, dp[n][k][i]);
        }
        cout << (ans == LLONG_MAX ? -1 : ans);
    }
    else
    {
        cout << (dp[n][k][c[n]] == LLONG_MAX ? -1 : dp[n][k][c[n]]) << endl;
    }
}

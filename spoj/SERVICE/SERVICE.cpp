#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t; cin >> t;
    while(t--)
    {
        int m, n; cin >> m >> n;

        int c[m + 1][m + 1] = {};
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++)
                cin >> c[i][j];

        int a[n + 1] = {};
        for(int i = 1; i <= n; i++) cin >> a[i];

        int dp[n + 1][m + 1][m + 1] = {};

        for(int i = 0; i <= n; i++)
            for(int j = 1; j <= m; j++)
                for(int k = 1; k <= m; k++)
                    dp[i][j][k] = INT_MAX;

        a[0] = 1;
        dp[0][2][3] = 1;
        dp[0][3][2] = 1;

        for(int i = 1; i <= n; i++)
        {
            // cout << i << endl;
            if(a[i] == a[i - 1])
            {
                for(int j = 1; j <= m; j++)
                {
                    for(int k = j + 1; k <= m; k++)
                    {
                        dp[i][j][k] = dp[i - 1][j][k];
                        dp[i][j][k] = dp[i - 1][k][j];
                    }
                }
            }
            else
            {
                for(int j = 1; j <= m; j++)
                {
                    for(int k = 1; k <= m; k++)
                    {
                        if(j == a[i - 1] || k == a[i - 1])
                        {
                            int nai = (j == a[i - 1] ? k : j);
                            int mn = INT_MAX;
                            for(int l = 1; l <= m; l++)
                            {
                                if(dp[i - 1][l][nai] != INT_MAX)
                                    mn = dp[i - 1][l][nai] + c[l][a[i]];
                            }
                            dp[i][j][k] = mn;
                            dp[i][k][j] = dp[i][j][k];
                        }
                        else
                        {
                            if(dp[i - 1][j][k] != INT_MAX)
                            {
                                dp[i][j][k] = dp[i - 1][j][k] + c[a[i - 1]][a[i]];
                                dp[i][k][j] = dp[i][j][k];
                            }
                        }
                    }
                }
            }
        }

        int mn = INT_MAX;

        for(int j = 1; j <= m; j++)
            for(int k = j + 1; k <= m; k++)
                mn = min(mn, dp[n][j][k]);
        cout << mn << "\n";
    }

    return 0;
}

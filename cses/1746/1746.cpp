#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007


int dp[200000][200];

int main(void)
{
    int n, m;
    cin >> n >> m;

    int x[n];
    for(int i = 0; i < n; i++) cin >> x[i];

    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            if(x[i] == 0)
            {
                for(int j = 1; j <= m; j++)
                {
                    dp[i][j] = 1;
                }
            }
            else if(x[i] != 0)
            {
                dp[i][x[i]] = 1;
            }
        }
        else
        {
            if(x[i] == 0)
            {
                for(int j = 1; j <= m; j++)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                    if(j > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                    if(j < m) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
                }
            }
            else if(x[i] != 0)
            {
                dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i]]) % MOD;
                if(x[i] > 1) dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i] - 1]) % MOD;
                if(x[i] < m) dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i] + 1]) % MOD;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; i++)
    {
        ans = (ans + dp[n - 1][i]) % MOD;
    }
    cout << ans << endl;
    return 0;
}

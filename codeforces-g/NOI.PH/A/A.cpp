#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, n; cin >> n;

    int dp[n + 1][n + 1][n + 1] = {};
    dp[0][0][0] = 1;

    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            for(int k = 0; k <= n; k++)
            {
                dp[i][j][k] = dp[i - 1][j][k];
                if(j - 1 >= 0) dp[i][j][k] += dp[i - 1][j - 1][k];
                if(k - 1 >= 0) dp[i][j][k] += dp[i - 1][j][k - 1];
                if(i == n && j > k) ans += dp[i][j][k];
            }
        }
    }

    cout << ans << endl;
}

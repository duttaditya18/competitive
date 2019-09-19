// LONG LONG LOL

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, W;
    cin >> n >> W;

    int  w[n], v[n];
    int  maxv = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
        maxv += v[i];
    }

    long long dp[n + 1][maxv + 1] = {};

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= maxv; j++)
            dp[i][j] = 2000000000;


    dp[0][0] = 0;
    long long maxtn = 0;
    for(int i = 1; i <= n; i++)
    {
        maxtn += v[i - 1];
        for(int j = 0; j <= maxtn; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j]);
            if(j >= v[i - 1])
            {
                dp[i][j] = min(dp[i - 1][j - v[i - 1]] + w[i - 1], dp[i][j]);
            }
        }
    }

    int ans = 0;

    for(int i = 0; i <= maxv; i++)
        if(dp[n][i] <= W)
            ans = max(ans, i);

    cout << ans << endl;

    /*for(int i = 0; i < n; i++)
        for(int j = 0; j <= maxv; j++)
            cout << i << " : " << j << " : " << dp[i][j] << endl;*/

    return 0;
}

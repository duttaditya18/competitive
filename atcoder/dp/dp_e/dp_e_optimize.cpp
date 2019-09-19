#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, c;
    cin >> n >> c;

    int w[n], v[n];
    int mxv = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
        mxv += v[i];
    }

    long long dp[2][mxv + 1];
    int mxtn = 0;

    for(int i = 0; i <= mxv; i++)
    {
        dp[0][i] = INT_MAX;
        dp[1][i] = INT_MAX;
    }

    dp[0][0] = 0;

    int t;

    for(int i = 1; i <= n; i++)
    {
        t = i % 2;
        mxtn += v[i - 1];
        for(int j = 0; j <= mxtn; j++)
        {
            dp[t][j] = min(dp[t][j], dp[!t][j]);
            if(j >= v[i - 1]) dp[t][j] = min(dp[t][j], dp[!t][j - v[i - 1]] + w[i - 1]);
        }
    }

    int ans = 0;

    for(int i = 0; i <= mxv; i++)
    {
        if(dp[t][i] <= c)
            ans = max(ans, i);
    }

    /*for(int i = 0; i < 2; i++)
        for(int j = 0; j <= mxv; j++)
            cout << i << " : " << j << " : " << dp[i][j] << endl;*/

    cout << ans << endl;
    return 0;

}

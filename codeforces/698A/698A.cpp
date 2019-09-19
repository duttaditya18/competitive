#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int x;

    // g[i][0] -- Gym, g[i][1] -- Contest
    int g[n][2] = {};

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        if(x == 0) g[i][0] = 0, g[i][1] = 0;
        if(x == 1) g[i][0] = 0, g[i][1] = 1;
        if(x == 2) g[i][0] = 1, g[i][1] = 0;
        if(x == 3) g[i][0] = 1, g[i][1] = 1;
    }

    // dp[i][0] -- Gym, dp[i][1] -- Contest, dp[i][2] -- Rest
    int dp[n][3];

    for(int i = 0; i < n; i++)
    {
        dp[i][0] = INT_MAX;
        dp[i][1] = INT_MAX;
        dp[i][2] = INT_MAX;
    }

    if(!g[0][0]) dp[0][0] = 1;
    else dp[0][0] = 0;
    if(!g[0][1]) dp[0][1] = 1;
    else dp[0][1] = 0;
    dp[0][2] = 1;

    /*for(int i = 0; i < n; i++)
    {
        cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
    }*/

    for(int i = 1; i < n; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]);
        if(!g[i][0]) dp[i][0]++;
        dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]);
        if(!g[i][1]) dp[i][1]++;
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
    }

    /*for(int i = 0; i < n; i++)
    {
        cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
    }*/

    int ans = INT_MAX;

    for(int i = 0; i < 3; i++)
        ans = min(ans, dp[n -1][i]);
    cout << ans;

    return 0;
}

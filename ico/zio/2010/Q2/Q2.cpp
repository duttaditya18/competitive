#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    // 0 - small, 1 - large
    int a[n + 1][2] = {}, x, y;

    for(int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        a[i][0] = min(x, y);
        a[i][1] = max(x, y);
    }

    // 0 - less, 1 - more
    int dp[n + 1][2] = {};
    dp[1][0] = a[1][0];
    dp[1][1] = a[1][1];

    dp[2][0] = a[2][0] + dp[1][0];
    dp[2][1] = a[2][1] + dp[1][0];

    for(int i = 3; i <= n; i++)
    {
        dp[i][0] = a[i][0] + max(dp[i - 1][0], dp[i - 2][1]);
        dp[i][1] = a[i][1] + max(dp[i - 1][0], dp[i - 2][1]);
    }

    // for(int i = 1; i <= n; i++) cout << dp[i][0] << " "; cout << endl;
    // for(int i = 1; i <= n; i++) cout << dp[i][1] << " "; cout << endl;
    cout << max({dp[n][0], dp[n][1], dp[n - 1][1]}) << endl;
}

// Eg: 4 1 2 1 3 1 -1 -2 -3
// (a): 10 2 -2 -3 -2 -3 -1 1 2 1 -5 4 -2 -4 -5 4 -5 -2 -5 5 4
// (b): 12 1 -1 -3 1 4 -1 -3 4 1 2 4 3 3 -4 4 1 4 2 -1 1 -2 -1 -3 -4
// (c): 14 -1 -5 1 -1 -3 5 -5 2 -2 -4 4 -4 -2 5 -3 -2 -3 4 3 -5 3 -5 -1 5 1 -1 3 4

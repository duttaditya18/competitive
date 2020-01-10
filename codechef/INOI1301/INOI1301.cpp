#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(void)
{
    int n, k; cin >> n >> k;
    int a[n + 1] = {};

    for(int i = 1; i <= n; i++) cin >> a[i];

    // 0 = k to j, 1 = 1 to j
    int dp[n + 1][2] = {};

    for(int i = k + 1; i <= n; i++) dp[i][0] = max(dp[i - 1][0], dp[i - 2][0]) + a[i];
    for(int i = 1; i <= n; i++)
    {
        dp[i][1] = a[i];
        if(i == 2) dp[i][1] += dp[i - 1][1];
        if(i >= 3) dp[i][1] += max(dp[i - 1][1], dp[i - 2][1]);
    }

    int ans = LLONG_MIN;

    for(int i = k; i <= n; i++) ans = max(ans, dp[i][0] + dp[i][1] - a[i]);
    cout << ans << endl;
}

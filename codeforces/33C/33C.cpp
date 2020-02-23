#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;

    int a[n + 1] = {};
    int dp[n + 2][2] = {};

    int cur = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cur += a[i];
        dp[i][0] = min(cur, dp[i - 1][0]);
    }
    cur = 0;
    for(int i = n; i >= 1; i--)
    {
        cur += a[i];
        dp[i][1] = min(cur, dp[i + 1][1]);
    }

    // for(int i = 1; i <= n; i++) cout << dp[i][0] << " "; cout << endl;
    // for(int i = 1; i <= n; i++) cout << dp[i][1] << " "; cout << endl;

    int ans = INT_MIN;

    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, cur - (2 * (dp[i][0] + dp[i + 1][1])));
    }
    cout << ans << endl;
}

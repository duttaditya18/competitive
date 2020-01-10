#include <bits/stdc++.h>

using namespace std;
#define MAXN 1000010
#define int long long

// 0 = Min L, 1 = Max Corner Missing L from Left, 2 = Max Corner Missing L from Right
int dp[3][MAXN];
int a[MAXN];
int b[MAXN];

signed main(void)
{
    int n; cin >> n;
    int ma0 = LLONG_MIN;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ma0 = max(ma0, a[i]);
    }
    for(int i = 1; i <= n; i++) cin >> b[i];

    // 0
    int cur = b[1] - a[1];
    dp[0][1] = cur;
    for(int i = 2; i <= n; i++)
    {
        cur = cur + a[i - 1] + b[i] - a[i];
        dp[0][i] = min(dp[0][i - 1], cur);
    }
    // for(int i = 1; i <= n; i++) cout << dp[0][i] << " "; cout << endl;

    // 1
    cur = a[1];
    dp[1][1] = cur;
    for(int i = 2; i <= n; i++)
    {
        cur = cur - a[i - 1] + b[i - 1] + a[i];
        dp[1][i] = cur;
    }
    // for(int i = 1; i <= n; i++) cout << dp[1][i] << " "; cout << endl;

    // 2
    cur = a[n];
    dp[2][n] = cur;
    for(int i = n - 1; i >= 1; i--)
    {
        cur = cur - a[i + 1] + b[i + 1] + a[i];
        dp[2][i] = max(dp[2][i + 1], cur);
    }
    // for(int i = 1; i <= n; i++) cout << dp[2][i] << " "; cout << endl;

    int ma1 = LLONG_MIN;
    for(int i = 2; i <= n; i++) ma1 = max(ma1, dp[1][i] - dp[0][i - 1]);
    int ma2 = LLONG_MIN;
    for(int i = 1; i <= n - 1; i++) ma2 = max(ma2, dp[1][i] + dp[2][i + 1]);

    cout << max({ma0, ma1, ma2}) << endl;
}

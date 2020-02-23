#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(void)
{
    int n; cin >> n;

    int a[n + 1] = {};
    for(int i = 1; i <= n; i++) cin >> a[i];

    int dp[n + 2] = {};

    dp[n] = (a[n] / 2);

    for(int i = n - 1; i >= 1; i--)
    {
        dp[i] = max((a[i] / 2) + dp[i + 1], dp[i + 2] + a[i + 1] + ((a[i] - a[i + 1]) / 2));
    }
    cout << dp[1] << endl;
}

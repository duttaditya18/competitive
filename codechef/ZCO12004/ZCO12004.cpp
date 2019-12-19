#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;

    int a[n] = {};
    for(int i = 0; i < n; i++) cin >> a[i];

    // 0 - Picking last (not necessarily picking first), 1 - Nessecarily picking first
    int dp[n][2] = {};

    dp[0][0] = a[0]; dp[1][0] = a[1];
    dp[0][1] = a[0]; dp[1][1] = a[1] + dp[0][1];

    for(int i = 2; i < n; i++)
    {
        dp[i][0] = min(dp[i - 1][0], dp[i - 2][0]) + a[i];
        dp[i][1] = min(dp[i - 1][1], dp[i - 2][1]) + a[i];
    }

    // for(int i = 0; i < n; i++) cout << dp[i][0] << " "; cout << endl;
    // for(int i = 0; i < n; i++) cout << dp[i][1] << " "; cout << endl;

    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 2][1]}) << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;
    long long h[n + 1][2] = {};

    for(int i = 1; i <= n; i++) cin >> h[i][0];
    for(int i = 1; i <= n; i++) cin >> h[i][1];

    // 0 - 1st row, 1 - 2nd row, 2 - nothing
    long long dp[n + 1][3] = {};

    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + h[i][0];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + h[i][1];
        dp[i][2] = max({dp[i - 1][0], dp[i - 1][1]});
    }

    // for(int i = 0; i <= n; i++) cout << dp[i][0] << " "; cout << endl;
    // for(int i = 0; i <= n; i++) cout << dp[i][1] << " "; cout << endl;
    // for(int i = 0; i <= n; i++) cout << dp[i][2] << " "; cout << endl;

    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}

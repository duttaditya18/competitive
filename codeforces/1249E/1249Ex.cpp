#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, c; cin >> n >> c;

    int a[n] = {}, b[n] = {};
    for(int i = 1; i < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) cin >> b[i];

    // 0 - stairs, 1 - elevator
    int dp[2][2] = {};
    dp[1][0] = a[1];
    dp[1][1] = c + b[1];
    cout << min(dp[0][0], dp[0][1]) << " " << min(dp[1][0], dp[1][1]) << " ";

    for(int i = 2; i <= n - 1; i++)
    {
        dp[i % 2][0] = min(dp[(i - 1) % 2][0] + a[i], dp[(i - 1) % 2][1] + a[i]);
        dp[i % 2][1] = min(dp[(i - 1) % 2][1] + b[i], dp[(i - 1) % 2][0] + c + b[i]);
        cout << min(dp[i % 2][0], dp[i % 2][1]) << " \n"[i == n - 1];
    }
}

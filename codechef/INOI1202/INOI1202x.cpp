#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;
    int a[n + 1] = {};

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += i;
    }

    // 0 = Prefix Max, 1 = Suffix Max
    int dp[n + 2][2] = {};

    for(int i = 1; i <= n; i++) dp[i][0] = max(dp[i - 1][0], a[i]);
    for(int i = n; i >= 0; i--) dp[i][1] = max(dp[i + 1][1], a[i]);

    for(int i = n; i >= 1; i--) cout << max(dp[i][0], dp[i + 1][1] - n) + (n - i) << " \n"[i == 1];

    return 0;
}

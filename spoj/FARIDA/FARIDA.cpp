#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    int q = t;

    while(q--)
    {
        int n;
        cin >> n;
        int a[n];

        // 0 - Not Taken, 1 - Taken
        long long dp[n + 1][2] = {};
        int x;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            dp[i + 1][0] = max(dp[i][0], dp[i][1]);
            dp[i + 1][1] = dp[i][0] + (1ll * x);
            // cout << dp[i + 1][0] << " " << dp[i + 1][1] << "\n";
        }

        cout << "Case " << t - q << ": " << max(dp[n][0], dp[n][1]) << "\n";
    }
    return 0;
}

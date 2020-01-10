#include <bits/stdc++.h>

using namespace std;

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC; cin >> TC;

    while(TC--)
    {
        int x, y, n, m; cin >> n >> m;

        int q[n];
        pair<int, int> tp[m];

        for(int i = 0; i < n; i++) cin >> q[i];
        for(int i = 0; i < m; i++) cin >> tp[i].second;
        for(int i = 0; i < m; i++) cin >> tp[i].first;

        sort(tp, tp + m);

        // n = Classified Jobs, m = Public Jobs
        // dp[i][j] = Least finishing time of first i Classified and first j Public Jobs
        long long dp[n + 1][m + 1] = {};

        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                if(i || j) dp[i][j] = LLONG_MAX;
                if(i) if(dp[i - 1][j] != LLONG_MAX) dp[i][j] = min(dp[i][j], dp[i - 1][j] + q[i - 1]);
                if(j) if(dp[i][j - 1] != LLONG_MAX)
                {
                    if(dp[i][j - 1] < tp[j - 1].first)
                        dp[i][j] = dp[i][j] = min(dp[i][j], max(dp[i][j - 1] + tp[j - 1].second, 1ll * tp[j - 1].first));
                }
            }
        }

        cout << (dp[n][m] == LLONG_MAX ? -1 : dp[n][m]) << "\n";
    }
}

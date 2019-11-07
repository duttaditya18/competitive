#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n;
        cin >> k;

        int v[n + 1], w[n + 1];

        for(int i = 1; i <= n; i++) cin >> v[i];
        for(int i = 1; i <= n; i++) cin >> w[i];

        int dp[n + 1][k + 1] = {};

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= k; j++)
            {
                if(w[i] <= j)
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        cout << dp[n][k] << endl;
    }
}

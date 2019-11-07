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

        int v[n + 1] = {}, w[n + 1] = {};

        for(int i = 1; i <= n; i++) cin >> v[i];
        for(int i = 1; i <= n; i++) cin >> w[i];

        int dp[k + 1] = {};

        for(int i = 1; i <= n; i++)
        {
            for(int j = k; j >= 0; j--)
            {
                if(j < w[i]) break;
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
                // cout << i << " " << j << " " << dp[j] << endl;
            }
        }

        // for(int i = 0; i <= k; i++) cout << dp[i] << " ";
        // cout << endl;
        cout << dp[k] << endl;
    }
}

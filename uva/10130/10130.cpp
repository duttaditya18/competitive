#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int v[n + 1] = {}, w[n + 1] = {};
        for(int i = 1; i <= n; i++)
        {
            cin >> v[i] >> w[i];
        }

        int g;
        cin >> g;

        int ans = 0;

        int k;

        while(g--)
        {
            cin >> k;

            int dp[k + 1] = {};

            for(int i = 1; i <= n; i++)
            {
                for(int j = k; j >= 0; j--)
                {
                    if(j < w[i]) break;
                    dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
                }
            }
            ans += dp[k];
        }
        cout << ans << endl;
    }
}

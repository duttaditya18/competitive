#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    // ofstream cout("output.txt");

    int n, t; cin >> t;
    char c;

    for(int k = 1; k <= t; k++)
    {
        cin >> n;

        int a[n + 1] = {};
        int dp[n + 1] = {};
        for(int i = 1; i <= n; i++)
        {
            cin >> c;
            a[i] = (c == '.');
        }

        dp[1] = a[1];

        for(int i = 2; i <= n; i++)
        {
            if(!a[i]) dp[i] = dp[i - 1];
            else
            {
                dp[i] = 1 + dp[i - 2];
                if(i >= 3) dp[i] = min(dp[i], 1 + dp[i - 3]);
            }
        }
        cout << "Case " << k << ": " << dp[n] << "\n";
    }
    return 0;
}

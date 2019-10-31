#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    int a[m];
    for(int i = 0; i < m; i++) cin >> a[i];

    long long dp[n + 1] = {};

    dp[0] = 1ll;

    for(int j = 0; j < m; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(i >= a[j])
            {
                dp[i] += dp[i - a[j]];
            }
        }
    }

    // for(int i = 0; i <= n; i++) cout << dp[i] << endl;
    cout << dp[n] << endl;
}

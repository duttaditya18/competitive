#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main(void)
{
    int k, n, to = 0; cin >> k >> n;

    int dp[n + 1][k + 1] = {};
    dp[0][1] = 1;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= k; j++)
            for(int f = j; f <= k; f += j)
                dp[i][f] = (dp[i][f] + dp[i - 1][j]) % mod;

    for(int i = 1; i <= k; i++) to = (to + dp[n][i]) % mod;
    cout << to << "\n";
    return 0;
}

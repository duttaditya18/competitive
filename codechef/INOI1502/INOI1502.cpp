#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, MOD; cin >> n >> MOD;

    // 0 = Periodic, 1 = Non-Periodic
    int dp[n + 1][2] = {};

    int two = 1;

    for(int i = 1; i <= n; i++)
    {
        two = (two * 2) % MOD;
        dp[i][1] = two;
    }

    for(int i = 1; i <= (n / 2); i++)
    {
        for(int j = i + i; j <= n; j += i)
        {
            dp[j][0] = (dp[j][0] + dp[i][1]) % MOD;
            dp[j][1] = (dp[j][1] - dp[i][1]) % MOD;
        }
    }

    cout << ((dp[n][1] % MOD) + MOD) % MOD << endl;

    return 0;
}

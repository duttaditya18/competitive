#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int dp[2][1000010] = {};

int numWays(int s, int l)
{
    dp[0][1] = 1;

    l--;

    l = min((s / 2), l);

    for(int i = 1; i <= s; i++)
    {
        for(int j = 1; j <= l + 1; j++)
        {
            int c = i % 2;
            dp[c][j] = (1ll * dp[!c][j - 1] + dp[!c][j] + dp[!c][j + 1]) % mod;
        }
    }
    return dp[s % 2][1];
}

int main(void)
{
    cout << numWays(27, 7);
}

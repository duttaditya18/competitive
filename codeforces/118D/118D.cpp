#include <bits/stdc++.h>

using namespace std;
#define MAXN 110
#define MOD 100000000

int n1, n2, k1, k2;
int dp[MAXN][MAXN][2];

// cur = 0 - Put n1's, cur = 1 - Put n2's
int rec(int u1, int u2, int cur, int fl)
{
    // for(int i = 0; i < fl; i++) cout << " ";
    // cout << u1 << u2  << cur << endl;

    if(u1 == n1 && u2 == n2) return 1;

    if(u1 == n1 && cur == 0) return 0;
    if(u2 == n2 && cur == 1) return 0;

    if(dp[u1][u2][cur] != -1) return dp[u1][u2][cur];

    int ans = 0;
    if(cur == 0)
    {
        for(int i = 1; i <= k1; i++)
        {
            if(u1 + i <= n1) ans = (ans + rec(u1 + i, u2, !cur, fl + 1)) % MOD;
        }
    }
    else if(cur == 1)
    {
        for(int i = 1; i <= k2; i++)
        {
            if(u2 + i <= n2) ans = (ans + rec(u1, u2 + i, !cur, fl + 1)) % MOD;
        }
    }
    dp[u1][u2][cur] = (ans % MOD);
    return dp[u1][u2][cur];
}

int main(void)
{
    cin >> n1 >> n2 >> k1 >> k2;

    for(int i = 0; i < MAXN; i++)
    {
        for(int j = 0; j < MAXN; j++)
        {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }

    cout << (rec(0, 0, 0, 0) + rec(0, 0, 1, 0)) % MOD << endl;
}

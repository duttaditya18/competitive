#include <bits/stdc++.h>

using namespace std;
#define MAXN 501

int dp[2][MAXN][MAXN];

int main(void)
{
    int n, m, b, mod; cin >> n >> m >> b >> mod;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];

    dp[0][0][0] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            for(int k = 0; k <= b; k++)
            {
                dp[i % 2][j][k] = dp[!(i % 2)][j][k] % mod;
                if(k - a[i] >= 0 && j >= 1) dp[i % 2][j][k] = (dp[i % 2][j][k] + dp[i % 2][j - 1][k - a[i]]) % mod;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= b; i++) ans = (ans + dp[n % 2][m][i]) % mod;
    cout << ans << endl;
}

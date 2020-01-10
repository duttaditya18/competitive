#include <bits/stdc++.h>

using namespace std;
#define MAXN 1510

int n, m;
long long dp[MAXN][MAXN];
int p[MAXN][MAXN];

signed main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> p[i][j];
            p[i][j] += p[i][j - 1];
        }
    }

    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= m + 1; j++)
            dp[i][j] = LLONG_MIN;

    for(int i = 1; i <= n; i++)
    {
        if(i % 2)
        {
            for(int j = m; j >= 2; j--)
            {
                dp[i][j] = max(p[i][j] + dp[i - 1][j - 1], dp[i][j + 1]);
            }
        }
        else
        {
            for(int j = 1; j <= m - 1; j++)
            {
                dp[i][j] = max(p[i][j] + dp[i - 1][j + 1], dp[i][j - 1]);
            }
        }
    }

    long long ans = LLONG_MIN;
    int st = (n % 2 ? 2 : 1);
    int en = (n % 2 ? m : m - 1);

    for(int j = st; j <= en; j++)
        ans = max(ans, dp[n][j]);

    cout << ans << endl;
}

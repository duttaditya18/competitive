#include <bits/stdc++.h>

using namespace std;
#define MAXN 5010

long long n, m, k;
long long a[MAXN], p[MAXN];
long long dp[MAXN][MAXN];

int main(void)
{
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[i] = a[i] + p[i - 1];
    }

    for(int i = 0; i <= n + 1; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            if(j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = LLONG_MIN;
        }
    }

    for(int i = 1; i <= k; i++)
    {
        for(int j = n; j >= 1; j--)
        {
            if(!(n - j + 1 < m * i)) dp[j][i] = max(dp[j + 1][i], p[j + m - 1] - p[j - 1] + dp[j + m][i - 1]);
            // cout << i << " " << j << " " << dp[j][i] << endl;
        }
    }

    cout << dp[1][k];
}

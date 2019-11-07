#include <bits/stdc++.h>

using namespace std;
#define MAXN 5010

long long n, m, k;
long long a[MAXN], p[MAXN];
long long dp[MAXN][MAXN];

long long rec(long long st, long long k)
{
    // cout << st << " " << k << endl;
    if(dp[st][k] != -1) return dp[st][k];
    if(m * k > (n - st + 1)) return LLONG_MIN;
    if(k < 1) return 0;

    dp[st][k] = max(rec(st + 1, k), p[st + m - 1] - p[st - 1] + rec(st + m, k - 1));
    return dp[st][k];
}

int main(void)
{
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[i] = a[i] + p[i - 1];
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << rec(1, k);
}

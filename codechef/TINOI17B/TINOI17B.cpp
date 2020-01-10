#include <bits/stdc++.h>

using namespace std;
#define MAXN 5010

long long dp[2][MAXN];

int main(void)
{
    int n; cin >> n;

    long long st[n + 2] = {};
    cin >> st[1];

    for(int i = 2; i <= n + 1; i++)
    {
        long long pr = st[i - 1], x = 10, cur = 0;

        st[i] = st[i - 1];
        while(pr != 0)
        {
            cur += (pr % x);
            pr /= x;
        }
        st[i] += (cur*cur*cur);
        // cout << st[i] << endl;
    }

    int e[n + 1] = {};
    for(int i = 1; i <= n; i++) cin >> e[i];

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            dp[i % 2][j] = max(dp[!(i % 2)][j - 1], dp[!(i % 2)][j] + e[i] * st[j]);
        }
    }

    long long ans = 0;
    for(int j = 1; j <= n; j++) ans = max(ans, dp[n % 2][j]);
    cout << ans << endl;
}

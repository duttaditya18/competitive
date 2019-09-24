#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, p, q, r;
    cin >> n >> p >> q >> r;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long dp[n][3];

    dp[0][0] = (long long) a[0] * p;

    for(int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], (long long) a[i] * p);
    }

    dp[0][1] = dp[0][0] + (long long) a[0] * q;

    for(int i = 1; i < n; i++)
    {
        dp[i][1] = max(dp[i - 1][1], dp[i][0] + (long long) a[i] * q);
    }

    dp[0][2] = dp[0][1] + (long long) a[0] * r;

    for(int i = 1; i < n; i++)
    {
        dp[i][2] = max(dp[i - 1][2], dp[i][1] + (long long) a[i] * r);
    }

    cout << dp[n - 1][2] << endl;
    return 0;
}

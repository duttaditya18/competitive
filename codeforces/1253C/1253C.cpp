#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m; cin >> n >> m;
    long long a[n] = {}, dp[n] = {};

    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    long long cur = 0;

    for(int i = 0; i < n; i++)
    {
        cur += a[i];
        dp[i] = cur;

        if(i >= m) dp[i] += dp[i - m];
        cout << dp[i] << " \n"[i == n - 1];
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
#define MAXN 1000010

int n, c, mf;
int dp[MAXN], a[MAXN];

int main(void)
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    int ans = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        dp[a[i]] = 1;
        c = a[i];
        c += a[i];

        while(c <= a[n - 1])
        {
            dp[a[i]] = max(dp[a[i]], dp[c] + 1);
            c += a[i];
        }
        ans = max(ans, dp[a[i]]);
    }

    // for(int i = 0; i < n; i++) cout << a[i] << " : " << dp[a[i]] << endl;

    cout << ans << "\n";
}

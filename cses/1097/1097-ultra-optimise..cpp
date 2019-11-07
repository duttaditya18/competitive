#include <bits/stdc++.h>

using namespace std;
#define MAXN 5001

int n, cur = 0;
long long a[MAXN], p[MAXN], dp[MAXN][2];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[i] = a[i] + p[i - 1];
    }

    for(int i = 1; i < n; i++)
    {
        cur = !cur;
        for(int j = 1; j <= n - i; j++)
        {
            if(i == 1) dp[j + i][cur] = max(a[j], a[j + i]);
            else dp[j + i][cur] = p[j + i] - p[j - 1] - min(dp[j + i][!cur], dp[j + i - 1][!cur]);
        }
    }

    cout << dp[n][1] << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long a[n + 1] = {}, p[n + 1] = {};
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[i] = a[i] + p[i - 1];
    }

    int cur = 0;

    long long dp[n + 1][2] = {};

    for(int i = 1; i < n; i++)
    {
        cur = !cur;
        for(int j = 1; j <= n - i; j++)
        {
            // cout << st << " " << en << " : ";
            if(i == 1)
            {
                dp[en][cur] = max(a[j], a[j + i]);
            }
            else dp[en][cur] = p[j + i] - p[j - 1] - min(dp[j + i][!cur], dp[j + i - 1][!cur]);
            // cout << dp[st][en] << endl;;
        }
    }

    // for(int i = 0; i <= n; i++) { for(int j = 0; j <= n; j++) cout << dp[i][j] << " "; cout << endl; } cout << endl;

    cout << dp[n][1] << endl;
}

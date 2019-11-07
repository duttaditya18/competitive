#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    long long a[n + 1] = {};
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // for(int i = 0; i <= n; i++) cout << a[i] << " "; cout << endl;

    long long dp[n + 1][n + 1] = {};

    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= n - i; j++)
        {
            int st = j;
            int en = j + i;
            // cout << st << " " << en << " : ";
            if(i == 0)
            {
                dp[j][j] = a[j];
                continue;
            }
            if(i == 1)
            {
                dp[st][en] = max(a[st], a[en]);
                continue;
            }
            dp[st][en] = max(a[st] + min(dp[st + 2][en], dp[st + 1][en - 1]), a[en] + min(dp[st + 1][en - 1], dp[st][en - 2]));
            // cout << dp[st][en][0] << " " << dp[st][en][1] << endl;;
        }
    }

    // for(int i = 0; i <= n; i++) { for(int j = 0; j <= n; j++) cout << dp[i][j] << " "; cout << endl; } cout << endl;

    cout << dp[1][n] << endl;
}

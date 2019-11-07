#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int a[n + 1] = {};
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        // for(int i = 0; i <= n; i++) cout << a[i] << " "; cout << endl;

        // 0 - First, 1 - Second
        int dp[n + 1][n + 1][2] = {};

        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= n - i; j++)
            {
                int st = j;
                int en = j + i;
                // cout << st << " " << en << " : ";
                if(i == 0)
                {
                    dp[j][j][0] = a[j];
                    dp[j][j][1] = 0;
                    continue;
                }
                if(a[st] + dp[st + 1][en][1] >= a[en] + dp[st][en - 1][1])
                {
                    dp[st][en][0] = a[st] + dp[st + 1][en][1];
                    dp[st][en][1] = dp[st + 1][en][0];
                }
                else
                {
                    dp[st][en][0] = a[en] + dp[st][en - 1][1];
                    dp[st][en][1] = dp[st][en - 1][0];
                }
                // cout << dp[st][en][0] << " " << dp[st][en][1] << endl;;
            }
        }

        // for(int i = 0; i <= n; i++) { for(int j = 0; j <= n; j++) cout << dp[i][j][0] << " "; cout << endl; } cout << endl;
        // for(int i = 0; i <= n; i++) { for(int j = 0; j <= n; j++) cout << dp[i][j][1] << " "; cout << endl; }

        cout << dp[1][n][0] << endl;
    }
}

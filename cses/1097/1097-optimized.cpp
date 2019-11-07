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
    // for(int i = 1; i <= n; i++) cout << p[i] << " "; cout << endl;
    // for(int i = 0; i <= n; i++) cout << a[i] << " "; cout << endl;

    long long dp[n + 1][n + 1] = {};

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= n - i; j++)
        {
            int st = j;
            int en = j + i;
            // cout << st << " " << en << " : ";
            if(i == 1)
            {
                dp[st][en] = max(a[st], a[en]);
            }
            else dp[st][en] = p[en] - p[st - 1] - min(dp[st + 1][en], dp[st][en - 1]);
            // cout << dp[st][en] << endl;;
        }
    }

    // for(int i = 0; i <= n; i++) { for(int j = 0; j <= n; j++) cout << dp[i][j] << " "; cout << endl; } cout << endl;

    cout << dp[1][n] << endl;
}

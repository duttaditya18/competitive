#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, x; cin >> n;

    char c;

    int a[n + 1] = {};
    // frequency
    int f[n + 1][26] = {};

    for(int i = 1; i <= n; i++)
    {
        cin >> c;
        a[i] = c - 'a';
        for(int j = 0; j < 26; j++)
        {
            f[i][j] = f[i - 1][j];
        }
        f[i][a[i]]++;
    }

    int dp[n + 1][26] = {};

    for(int k = 0; k < 26; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = i; j <= n; j++)
            {
                x = j - i + 1 - f[j][k] + f[i - 1][k];
                // cout << char(k + 'a') << " : " << i << " " << j << " : " << x << endl;
                dp[x][k] = max(dp[x][k], j - i + 1);
            }
        }
    }

    for(int i = 0; i < 26; i++)
        for(int j = 1; j <= n; j++)
            dp[j][i] = max(dp[j][i], dp[j - 1][i]);

    int m; cin >> m;
    while(m--)
    {
        cin >> x >> c;
        cout << dp[x][c - 'a'] << endl;
    }
    return 0;
}

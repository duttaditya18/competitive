#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m, x, y; cin >> n >> m >> x >> y;

    char c;

    int a[n + 1][m + 1] = {};

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> c;
            a[i][j] = (c == '.' ? 1 : 0);
        }

    }

    for(int i = 1; i <= n; i++) { for(int j = 0; j <= m; j++) cout << a[i][j] << " "; cout << endl; }

    // white
    int prf[m + 1] = {};

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            prf[j] += (a[i][j]);

    for(int i = 1; i <= m; i++) prf[i] += prf[i - 1];

    for(int i = 0; i <= m; i++) cout << prf[i] << " "; cout << endl;

    // 0 - black, 1 - white
    int dp[m + 1][2] = {};

    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = prf[1];
    dp[1][1] = n - prf[1];

    int z;

    for(int i = 2; i <= m; i++)
    {
        dp[i][0] = INT_MAX;
        dp[i][1] = INT_MAX;
        for(int j = x; j <= y; j++)
        {
            z = i - j;
            if(z >= 0)
            {
                dp[i][0] = min(dp[i][0], dp[z][1] + prf[i] - prf[z]);
                dp[i][1] = min(dp[i][1], dp[z][0] + (j * n) - (prf[i] - prf[z]));
            }
        }
    }

    for(int i = 0; i <= m; i++) cout << dp[i][0] << " "; cout << endl;
    for(int i = 0; i <= m; i++) cout << dp[i][1] << " "; cout << endl;

    cout << min(dp[m][0], dp[m][1]) << endl;
}

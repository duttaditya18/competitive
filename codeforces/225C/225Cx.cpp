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
            if(c == '.') a[i][j] = 1;
        }
    }

    // count Whites (1's)
    int prf[m + 1] = {};

    for(int j = 1; j <= m; j++)
    {
        for(int i = 1; i <= n; i++)
            prf[j] += a[i][j];
        prf[j] += prf[j - 1];
    }

    // 0 - chose black, 1 - chose white
    int dp[m + 1][2] = {}, z;

    for(int i = 1; i <= m; i++)
    {
        dp[i][0] = INT_MAX;
        dp[i][1] = INT_MAX;
        for(int j = x; j <= y; j++)
        {
            z = i - j;
            if(z < 0) continue;
            if(dp[z][0] == INT_MAX || dp[z][1] == INT_MAX) continue;
            dp[i][0] = min(dp[i][0], dp[z][1] + prf[i] - prf[z]);
            dp[i][1] = min(dp[i][1], dp[z][0] + (j * n) - (prf[i] - prf[z]));
        }
    }

    // for(int i = 0; i <= m; i++) cout << dp[i][0] << " "; cout << endl;
    //  for(int i = 0; i <= m; i++) cout << dp[i][1] << " "; cout << endl;

    cout << min(dp[m][0], dp[m][1]) << endl;
}

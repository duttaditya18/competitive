#include <bits/stdc++.h>

using namespace std;
#define MAXN 1001

int a[MAXN][MAXN];
int dp[4][MAXN][MAXN];

int main(void)
{
    int n, m; cin >> n >> m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];

    // 0 = [(1, 1) -> (n, m)], 1 = [(n, 1) -> (1, m)], 2 = [(1, m) -> (n, 1)], 3 = [(n, m) -> (1, 1)]

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[0][i][j] = a[i][j] + max(dp[0][i - 1][j], dp[0][i][j - 1]);

    for(int i = n; i >= 1; i--)
        for(int j = 1; j <= m; j++)
            dp[1][i][j] = a[i][j] + max(dp[1][i + 1][j], dp[1][i][j - 1]);

    for(int i = 1; i <= n; i++)
        for(int j = m; j >= 1; j--)
            dp[2][i][j] = a[i][j] + max(dp[2][i - 1][j], dp[2][i][j + 1]);

    for(int i = n; i >= 1; i--)
        for(int j = m; j >= 1; j--)
            dp[3][i][j] = a[i][j] + max(dp[3][i + 1][j], dp[3][i][j + 1]);

    /*cout << endl;
    for(int i = 1; i <= n; i++) { for(int j = 1; j <= m; j++) cout << dp[0][i][j] << " "; cout << endl; } cout << endl;
    for(int i = 1; i <= n; i++) { for(int j = 1; j <= m; j++) cout << dp[1][i][j] << " "; cout << endl; } cout << endl;
    for(int i = 1; i <= n; i++) { for(int j = 1; j <= m; j++) cout << dp[2][i][j] << " "; cout << endl; } cout << endl;
    for(int i = 1; i <= n; i++) { for(int j = 1; j <= m; j++) cout << dp[3][i][j] << " "; cout << endl; } cout << endl;*/

    long long ans = 0;
    for(int i = 2; i <= n - 1; i++)
        for(int j = 2; j <= m - 1; j++)
        {
            // cout << i << "  " << j << endl;
            ans = max({ans, 1ll * dp[0][i - 1][j] + dp[3][i + 1][j] + dp[1][i][j - 1] + dp[2][i][j + 1], 1ll * dp[0][i][j - 1] + dp[3][i][j + 1] + dp[1][i + 1][j] + dp[2][i - 1][j]});
        }

    cout << ans << endl;
}

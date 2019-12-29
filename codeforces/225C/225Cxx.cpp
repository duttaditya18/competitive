#include <bits/stdc++.h>

using namespace std;

int n, m, x, y;
int dp[1001][2] = {};
int prf[1001] = {};
char c;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x >> y;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            cin >> c;
            if(c == '.') prf[j]++;
        }

    for(int j = 1; j <= m; j++) prf[j] += prf[j - 1];

    for(int i = 1; i <= m; i++)
    {
        dp[i][0] = INT_MAX;
        dp[i][1] = INT_MAX;
        for(int j = x; j <= y; j++)
        {
            if(i - j < 0) continue;
            if(dp[i - j][0] == INT_MAX || dp[i - j][1] == INT_MAX) continue;
            dp[i][0] = min(dp[i][0], dp[i - j][1] + prf[i] - prf[i - j]);
            dp[i][1] = min(dp[i][1], dp[i - j][0] + (j * n) - (prf[i] - prf[i - j]));
        }
    }

    cout << min(dp[m][0], dp[m][1]) << endl;
}

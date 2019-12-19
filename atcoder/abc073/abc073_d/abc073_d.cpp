#include <bits/stdc++.h>

using namespace std;
#define INF 1000000000

int main(void)
{
    int n, m, r, a, b, c;
    cin >> n >> m >> r;

    vector<int> rs;
    int adj[n + 1][n + 1] = {};
    for(int i = 0; i < r; i++)
    {
        cin >> a;
        rs.push_back(a);
    }

    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a][b] = c;
        adj[b][a] = c;
    }

    // for(int i = 0; i <= n; i++) { for(int j = 0; j <= n; j++) { cout << adj[i][j]; } cout << endl; } cout << endl;

    int dp[n + 1][n + 1] = {};

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j) dp[i][j] = 0;
            else if(adj[i][j]) dp[i][j] = adj[i][j];
            else dp[i][j] = INF;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= n; k++)
            {
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    }
    // for(int i = 0; i <= n; i++) { for(int j = 0; j <= n; j++) { cout << dp[i][j]; } cout << endl; } cout << endl;

    sort(rs.begin(), rs.end());

    long long mi = INF, cur;

    do
    {
        cur = 0;
        for(int i = 0; i < r - 1; i++)
        {
            cur += 1ll*dp[rs[i]][rs[i + 1]];
        }
        mi = min(mi, cur);
    }
    while(next_permutation(rs.begin(), rs.end()));

    cout << mi << endl;
}

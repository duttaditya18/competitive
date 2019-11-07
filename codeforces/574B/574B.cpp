#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    bool adj[n + 1][n + 1] = {};
    int deg[n + 1] = {};
    int a, b;

    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a][b] = 1; adj[b][a] = 1;
        deg[a]++; deg[b]++;
    }

    int ans = INT_MAX;

    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(adj[i][j])
            {
                for(int k = j + 1; k <= n; k++)
                {
                    if(adj[j][k] && adj[k][i])
                    {
                        ans = min(ans, deg[i] + deg[j] + deg[k]);
                    }
                }
            }
        }
    }

    cout << (ans == INT_MAX ? -1 : ans - 6) << endl;
}

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

int main(void)
{
    int a, b, n, m, s, t; cin >> n >> m >> s >> t;

    vector<int> adj[n + 1];
    int adm[n + 1][n + 1] = {};

    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        adm[a][b] = 1;
        adm[b][a] = 1;
    }

    int dist[n + 1][n + 1] = {};

    for(auto i : {s, t})
    {
        queue<pair<int, int>> q;
        int vis[n + 1] = {};

        q.push({i, 0});
        vis[i] = 1;
        dist[i][i] = 0;

        while(!q.empty())
        {
            pair<int, int> t = q.front(); q.pop();
            dist[i][t.fi] = t.se;

            for(auto u : adj[t.fi])
            {
                if(vis[u]) continue;
                q.push({u, t.se + 1});
                vis[u] = 1;
            }
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(!adm[i][j] && (dist[s][i] + 1 + dist[t][j]) >= dist[s][t]) ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}

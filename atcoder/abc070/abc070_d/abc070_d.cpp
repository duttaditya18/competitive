#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(void)
{
    int a, b, c, n; cin >> n;

    vector<pair<int, int>> adj[n + 1];
    for(int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }

    int tc, k; cin >> tc >> k;

    queue<pair<int, int>> q;
    int vis[n + 1] = {};
    int dist[n + 1] = {};

    q.push(make_pair(k, 0));
    vis[k] = 1;

    while(!q.empty())
    {
        int t = q.front().first;
        int d = q.front().second;
        dist[t] = d;
        q.pop();

        for(auto u : adj[t])
        {
            if(!vis[u.first])
            {
                q.push(make_pair(u.first, d + u.second));
                vis[u.first] = 1;
            }
        }
    }

    while(tc--)
    {
        cin >> a >> b;
        cout << dist[a] + dist[b] << endl;
    }
}

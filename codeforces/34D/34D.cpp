#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, x, r, c; cin >> n >> r >> c;

    vector<int> adj[n + 1];

    for(int i = 1; i <= n; i++)
    {
        if(i == r) continue;
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    queue<int> q;
    int p[n + 1] = {};
    int vis[n + 1] = {};

    q.push(c);
    vis[c] = 1;

    while(!q.empty())
    {
        int t = q.front(); q.pop();

        for(auto u : adj[t])
        {
            if(vis[u]) continue;

            q.push(u);
            vis[u] = 1;
            p[u] = t;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(i == c) continue;

        cout << p[i] << " \n"[i == n];
    }
    return 0;
}

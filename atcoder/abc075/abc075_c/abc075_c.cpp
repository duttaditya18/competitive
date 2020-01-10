#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int x, y, n, m; cin >> n >> m;

    // Tail, Edge Number
    vector<pair<int, int>> adj[n + 1];

    for(int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(make_pair(y, i));
        adj[y].push_back(make_pair(x, i));
    }

    int ans = 0;

    for(int i = 1; i <= m; i++)
    {
        queue<int> q;
        int vis[n + 1] = {};

        q.push(1);
        vis[1] = 1;

        while(!q.empty())
        {
            int t = q.front(); q.pop();

            for(auto u : adj[t])
            {
                if(!vis[u.first] && u.second != i)
                {
                    q.push(u.first);
                    vis[u.first] = 1;
                }
            }
        }

        for(int j = 1; j <= n; j++)
        {
            if(!vis[j])
            {
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;
}

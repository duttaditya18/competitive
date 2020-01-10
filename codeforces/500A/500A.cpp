#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int x, n, t; cin >> n >> t;

    vector<int> adj[n + 1];

    for(int i = 1; i <= n - 1; i++)
    {
        cin >> x;
        adj[i].push_back(i + x);
    }

    stack<int> q;
    int vis[n + 1] = {};

    q.push(1);
    vis[1] = 1;

    bool f = false;

    while(!q.empty())
    {
        int x = q.top(); q.pop();
        // cout << x << endl;

        if(x == t)
        {
            f = true;
            break;
        }
        for(auto u : adj[x])
        {
            if(!vis[u])
            {
                q.push(u);
                vis[u] = 1;
            }
        }
    }

    cout << (f ? "YES" : "NO") << "\n";
}

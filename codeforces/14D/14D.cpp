#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int x, y, n; cin >> n;

    vector<int> adj[n + 1];

    for(int i = 1; i < n; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // leaf nodes
    int k = 0;

    queue<int> q;
    int visited[n + 1] =  {};

    visited[1] = 1;
    q.push(1);

    while(!q.empty())
    {
        int t = q.front(); q.pop();

        // children
        int c = 0;
        for(auto u : adj[t])
        {
            if(!visited[u])
            {
                c++;
                visited[u] = 1;
                q.push(u);
            }
        }
        if(!c) k++;
    }

    int b[k + 1] = {};
    vector<int> ans;

    for(int i = 1; i <= k; i++)
    {
        cin >> b[i];
        int fr, to;
        if(i == 1)
        {
            fr = 1;
            to = b[i];
        }
        else
        {
            fr = b[i - 1];
            to = b[i];
        }

        queue<int> q;
        int vis[n + 1] = {}, parn[n + 1] = {};
        vis[fr] = 1;
        q.push(fr);

        while(!q.empty())
        {
            int t = q.front(); q.pop();
            // cout << t << endl;
            if(t == to) break;

            for(auto u : adj[t])
            {
                if(!vis[u])
                {
                    vis[u] = 1;
                    parn[u] = t;
                    q.push(u);
                }
            }
        }

        vector<int> path;

        while(parn[to] != 0)
        {
            path.push_back(to);
            to = parn[to];
        }
        if(i == 1) path.push_back(1);

        for(int g = 0, h = path.size() - 1; h >= g; h--)  ans.push_back(path[h]);
    }

    int fr = b[k], to = 1;
    int vis[n + 1] = {}, parn[n + 1] = {};
    vis[fr] = 1;
    q.push(fr);

    while(!q.empty())
    {
        int t = q.front(); q.pop();
        // cout << t << endl;
        if(t == to) break;

        for(auto u : adj[t])
        {
            if(!vis[u])
            {
                vis[u] = 1;
                parn[u] = t;
                q.push(u);
            }
        }
    }

    vector<int> path;

    while(parn[to] != 0)
    {
        path.push_back(to);
        to = parn[to];
    }

    for(int g = 0, h = path.size() - 1; h >= g; h--)  ans.push_back(path[h]);
    if(ans.size() != (2*n - 1))
    {
        cout << -1 << endl;
        return 0;
    }
    for(auto u : ans) cout << u << " "; cout << endl;
}

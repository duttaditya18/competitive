#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, u, v, x, y; cin >> n >> u >> v;

    int ru[n + 1] = {}, rv[n + 1] = {};

    vector<int> adj[n + 1];

    for(int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int visited[n + 1] = {};

    // cur, depth
    queue<tuple<int, int>> q;

    tuple<int, int> t;
    int cur, dep;

    q.push(make_tuple(u, 0));
    ru[u] = 0;
    visited[u] = true;

    while(!q.empty())
    {
        t = q.front();
        cur = get<0>(t);
        dep = get<1>(t);
        ru[cur] = dep;
        q.pop();

        for(auto h : adj[cur])
        {
            if(!visited[h])
            {
                visited[h] = true;
                q.push(make_tuple(h, dep + 1));
            }
        }
    }

    q.push(make_tuple(v, 0));
    rv[v] = 0;
    int visitex[n + 1] = {};
    visitex[v] = true;

    while(!q.empty())
    {
        t = q.front();
        cur = get<0>(t);
        dep = get<1>(t);
        rv[cur] = dep;
        q.pop();

        for(auto h : adj[cur])
        {
            if(!visitex[h])
            {
                visitex[h] = true;
                q.push(make_tuple(h, dep + 1));
            }
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        // cout << i << " " << ru[i] << " " << rv[i] << endl;
        if(ru[i] <= rv[i]) ans = max(ans, ru[i]);
    }
    cout << ans << endl;
}

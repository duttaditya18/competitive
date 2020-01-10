#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int a, b, c, n, m; cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];
    for(int i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        adj[b].push_back({a, c});
        adj[a].push_back({b, c});
    }

    priority_queue<pair<long long, int>> q;

    // distance, parent, visited
    vector<long long> d(n + 1, LLONG_MAX);
    vector<int> p(n + 1, 0), vis(n + 1, 0);

    q.push({0, 1});
    d[1] = 0;

    while(!q.empty())
    {
        int t = q.top().s; q.pop();

        if(vis[t]) continue;
        vis[t] = 1;

        for(auto u : adj[t])
        {
            int x = u.f, w = u.s;

            if(d[t] + w < d[x])
            {
                d[x] = d[t] + w;
                p[x] = t;
                q.push({-d[x], x});
            }
        }
    }

    if(!vis[n])
    {
        cout << -1 << "\n";
        return 0;
    }

    int cur = n;
    vector<int> ans;
    while(cur != 0)
    {
        ans.push_back(cur);
        cur = p[cur];
    }

    for(int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " \n"[i == 0];
    }
}

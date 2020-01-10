#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(void)
{
    int x, y, w, n; cin >> n;
    vector<pair<int, int>> adj[n + 1];

    int to = 0;

    for(int i = 1; i < n; i++)
    {
        cin >> x >> y >> w;
        to += w;
        adj[x].push_back(make_pair(y, w));
        adj[y].push_back(make_pair(x, w));
    }

    // current node, max distance so far
    queue<pair<int, int>> q;
    int visited[n + 1] = {};

    q.push(make_pair(1, 0));
    visited[1] = 1;

    int ma = 0;

    while(!q.empty())
    {
        pair<int, int> p = q.front(); q.pop();
        ma = max(ma, p.second);

        for(auto u : adj[p.first])
        {
            if(!visited[u.first])
            {
                visited[u.first] = 1;
                q.push(make_pair(u.first, p.second + u.second));
            }
        }
    }

    cout << (2*to) - ma << "\n";
}

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int x, n; cin >> n;
    vector<int> adj[n + 1];

    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        if(x != -1) adj[x].push_back(i);
    }

    // for(auto u : adj[2]) cout << u << " "; cout << endl;

    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        queue<pair<int, int>> q;
        int vis[n + 1] = {};

        q.push(make_pair(i, 1));
        vis[i] = 1;

        while(!q.empty())
        {
            int t = q.front().first;
            int d = q.front().second;
            // cout << t << " " << d << endl;
            ans = max(ans, d);
            q.pop();

            for(auto u : adj[t])
            {
                if(!vis[u])
                {
                    q.push(make_pair(u, d + 1));
                    vis[u] = 1;
                }
            }
        }
    }

    cout << ans << endl;
}

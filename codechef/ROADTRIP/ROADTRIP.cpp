#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t; cin >> t;

    while(t--)
    {
        int a, b, n, m, k; cin >> n >> m >> k;

        vector<int> adj[n + 1];

        for(int i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int c[n + 1] = {};

        for(int i = 1; i <= n; i++) cin >> c[i];

        int vis[n + 1] = {};

        vector<int> v;

        for(int i = 1; i <= n; i++)
        {
            if(vis[i]) continue;

            int meu = 0;

            queue<int> q;
            vis[i] = 1;
            q.push(i);

            while(!q.empty())
            {
                int t = q.front(); q.pop();
                meu += c[t];

                for(auto u : adj[t])
                {
                    if(!vis[u])
                    {
                        vis[u] = 1;
                        q.push(u);
                    }
                }
            }
            v.push_back(meu);
        }

        sort(v.begin(), v.end());
        if(k > v.size())
        {
            cout << -1 << endl;
            continue;
        }

        int ans = 0;

        // for(auto u : v) cout << u << " "; cout << endl;

        int x = k / 2;
        for(int i = 0; i < x; i++) ans += v[i];
        int l = v.size();
        for(int i = l - 1; i >= (l - (k - x)); i--) ans += v[i];
        cout << ans << endl;
    }
}

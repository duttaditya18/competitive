#include <bits/stdc++.h>

using namespace std;

#define MOD 998244353

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;

    while(t--)
    {
        int n, m; cin >> n >> m;

        vector<int> adj[n + 1];

        int a, b;
        for(int i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> vis(n + 1, 0);
        vector<int> clr(n + 1, -1);
        long long ans = 1;
        bool f = 1;

        for(int i = 1; i <= n && f; i++)
        {
            if(vis[i]) continue;
            queue<int> q;
            q.push(i);
            int o = 0, e = 1;
            vis[i] = 1;
            clr[i] = 0;

            while(!q.empty() && f)
            {
                int t = q.front(); q.pop();

                for(auto u : adj[t])
                {
                    if(vis[u])
                    {
                        if(clr[t] == clr[u])
                        {
                            f = false;
                            break;
                        }
                        continue;
                    }

                    q.push(u);
                    vis[u] = 1;
                    clr[u] = !clr[t];
                    o += clr[u];
                    e += !clr[u];
                }
            }

            int cur = 1;
            for(int i = 0; i < o; i++) cur = (cur * 2) % MOD;
            int cure = 1;
            for(int i = 0; i < e; i++) cure = (cure * 2) % MOD;
            long long x = (1ll*cur + cure) % MOD;
            ans = (ans * x) % MOD;
        }

        if(!f)
        {
            cout << 0 << "\n";
            continue;
        }

        cout << ans << "\n";
        // for(int i = 1; i <= n; i++) cout << clr[i] << " "; cout << endl;
    }
    return 0;
}

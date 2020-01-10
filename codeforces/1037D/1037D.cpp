#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n; cin >> n;

    int x, y;
    vector<int> adj[n + 1];
    for(int i = 1; i < n; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // node
    queue<int> q;
    int vis[n + 1] = {}, par[n + 1] = {}, chi[n + 1] = {};

    q.push(1);
    vis[1] = 1;
    par[1] = 0;
    chi[0] = 1;

    while(!q.empty())
    {
        int t = q.front();
        q.pop();

        for(auto u : adj[t])
        {
            if(vis[u]) continue;
            q.push(u);
            vis[u] = 1;
            par[u] = t;
            chi[t]++;
        }
    }

    // for(int i = 1; i <= n; i++) cout << chi[i] << " "; cout << endl;
    // for(int i = 1; i <= n; i++) cout << par[i] << " "; cout << endl;

    int cur = 0;
    int a[n + 1] = {};
    int k = 1;
    bool f = true;

    for(int i = 1; i <= n && f; i++)
    {
        for(int j = 1; j <= chi[cur]; j++)
        {
            cin >> a[k];
            if(par[a[k]] != cur)
            {
                f = false;
                break;
            }
            k++;
        }
        cur = a[i];
    }

    cout << (f ? "Yes" : "No") << "\n";

    // for(auto u : a) cout << u << " "; cout << endl;

    return 0;
}

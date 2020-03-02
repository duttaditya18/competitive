#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int main(void)
{
    int tfuc; cin >> tfuc;
    while(tfuc--)
    {
    int n, k, a, b; cin >> n >> k;

    vector<int> adj[n + 1];
    for(int i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<int> v;
    int vis[n + 1] = {};
    int chi[n + 1] = {};
    int prn[n + 1] = {};

    v.pb(1);
    vis[1] = 1;
    prn[1] = 0;
    int p = 0;

    while(p != v.size())
    {
        int t = v[p], c = 0;

        for(auto u : adj[t])
        {
            if(!vis[u])
            {
                c++;
                v.pb(u);
                vis[u] = 1;
                prn[u] = t;
            }
        }
        chi[t] = c;
        p++;
    }
    // for(int i = 1; i <= n; i++) cout << i << " : " << chi[i] << " " << prn[i] << "\n";
    // for(auto u : v) cout << u << " "; cout << "\n";

    p--;

    int an = 0;
    for(int i = 0; i < k; i++)
    {
        if(p < 0) break;
        int pp = p;
        while(chi[v[p]] == 0 && p >= 0)
        {
            // cout << i << " " << p << "\n";
            an++;
            p--;
            if(p < 0) break;
        }
        // cout << i << " " << p << " " << pp << endl;
        for(int j = p + 1; j <= pp; j++) chi[prn[v[j]]]--;
    }
    cout << an << "\n";
    }

    return 0;
}

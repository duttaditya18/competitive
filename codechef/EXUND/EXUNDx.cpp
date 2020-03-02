#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int maxn = 500200;

int n, k, a, b;
vector<int> adj[maxn];
int dp[maxn] = {};

void dfs(int t, int p)
{
    // cout << t << " " << p << endl;
    dp[t] = 0;
    for(auto u : adj[t])
    {
        if(u != p)
        {
            dfs(u, t);
            dp[t] = max(dp[u], dp[t]);
        }
    }
    dp[t]++;
    return;
}

int main(void)
{
    int tfuc; cin >> tfuc;
    while(tfuc--)
    {
        cin >> n >> k;
        for(int i = 1; i <= n; i++) adj[i].clear();
        for(int i = 1; i < n; i++)
        {
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        dfs(1, 0);
        int an = 0;
        // for(int i = 1; i <= n; i++) cout << dp[i] << " "; cout << endl;
        for(int i = 1; i <= n; i++) an += ((dp[i] <= k ? 1 : 0));
        cout << an << "\n";
    }

    return 0;
}

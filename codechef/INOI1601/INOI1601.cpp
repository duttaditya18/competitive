#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int x, n; cin >> n;

    int a[n + 1] = {};

    vector<int> adj[n + 1];

    for(int i = 1; i <= n; i++) cin >> a[i];

    int st;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        if(x == -1)
        {
            st = i;
            continue;
        }
        adj[x].push_back(i);
    }

    // Current Node, Maxmimum
    queue<pair<int, int>> q;
    q.push(make_pair(st, a[st]));

    int ans = INT_MIN;

    while(!q.empty())
    {
        int t = q.front().first;
        int ma = q.front().second;
        q.pop();

        ma = max(ma, a[t]);

        for(auto u : adj[t])
        {
            ans = max(ans, ma - a[u]);
            q.push(make_pair(u, ma));
        }
    }

    cout << max(0, ans) << endl;
}

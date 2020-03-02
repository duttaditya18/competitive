#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define mp make_pair

int main(void)
{
    int n, x, y; cin >> n;

    // 0 = to, 1 = from
    vector<pair<int, int>> adj[n + 1];
    for(int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        adj[x].pb(mp(y, 0));
        adj[y].pb(mp(x, 1));
    }

    // for(auto u : adj[1]) cout << u.fi << " " << u.se << endl;

    int dp[n + 1] = {};

    // node, parn
    queue<pair<int, int>> q;
    q.push(mp(1, 0));

    while(!q.empty())
    {
        int t = q.front().fi;
        // cout << t << endl;
        int p = q.front().se;
        q.pop();

        for(auto u : adj[t])
        {
            if(u.fi != p)
            {
                q.push(mp(u.fi, t));
                dp[1] += u.se;
            }
        }
    }
    // cout << dp[1] << endl;

    q.push(mp(1, 0));


    int mi = dp[1];
    vector<int> an;
    an.pb(1);

    while(!q.empty())
    {
        int t = q.front().fi;
        int p = q.front().se;
        q.pop();

        for(auto u : adj[t])
        {
            if(u.fi != p)
            {
                if(u.se) dp[u.fi] = dp[t] - 1;
                else dp[u.fi] = dp[t] + 1;
                if(dp[u.fi] < mi)
                {
                    // cout << u.fi << " " << t << endl;
                    mi = dp[u.fi];
                    an.clear();
                    an.pb(u.fi);
                }
                else if(dp[u.fi] == mi)
                {
                    an.pb(u.fi);
                    // cout << t<< " " << u.fi << endl;
                }
                q.push(mp(u.fi, t));
            }
        }
    }
    cout << mi << "\n";
    sort(an.begin(), an.end());
    for(auto u : an) cout << u << " ";
    cout << "\n";
    return 0;
}

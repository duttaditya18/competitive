#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    // ifstream cin("in.in");
    // ofstream cout("out.in");

    int t; cin >> t;

    while(t--)
    {
        int n, r, x, y; cin >> n >> r;

        unordered_set<int> adj[n];
        for(int i = 0; i < r; i++)
        {
            // cout << i << endl;
            cin >> x >> y;
            x--; y--;
            adj[x].insert(y);
            adj[y].insert(x);
        }

        queue<pair<int, ll>> q;

        // mask, n
        int dp[n][1LL << n]= {};

        q.push(make_pair(0, (1LL << 0)));
        dp[0][1LL << 0] = 1;

        bool f = false;

        while(!q.empty())
        {
            int t = q.front().fi;
            ll v = q.front().se;
            q.pop();

            if(__builtin_popcountll(v) == n)
            {
                f = true;
                break;
            }

            for(auto u : adj[t])
                if(!(v & (1LL << u)) && !dp[u][(v | (1LL << u))])
                {
                    q.push(make_pair(u, (v | (1LL << u))));
                    dp[u][(v | (1LL << u))] = 1;
                }
        }

        cout << (f ? "Hamster" : "Dam") << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int x, y, n, m; cin >> n >> m;

    int adj[n + 1][n + 1] = {};

    for(int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        adj[x][y] = adj[y][x] = 1;
    }
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);

    int ans = 0;

    do
    {
        // for(auto u : v) cout << u << " "; cout << endl;
        if(v[0] != 1) break;

        bool f = true;

        for(int i = 0; i < n - 1; i++)
        {
            if(!adj[v[i]][v[i + 1]])
            {
                f = false;
                break;
            }
        }
        if(f) ans++;
    }
    while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;
}

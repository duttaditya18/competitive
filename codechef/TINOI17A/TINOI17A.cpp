#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second

int main(void)
{
    int r, c, n; cin >> r >> c >> n;
    int ri, ci;
    set<pair<int, int>> st;

    for(int i = 0; i < n; i++)
    {
        cin >> ri >> ci;
        st.insert(make_pair(ri, ci));
    }

    set<pair<int, int>> vis;

    int ans = 0;

    for(auto u : st)
    {
        if(vis.count(u)) continue;
        // cout << u.fi << " " << u.se << endl;

        stack<pair<int, int>> q;
        q.push(u);
        vis.insert(u);
        int fen = 4;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while(!q.empty())
        {
            pair<int, int> t = q.top();
            q.pop();
            // cout << "   " << t.fi << " " << t.se << " " << fen << endl;
            for(int i = 0; i < 4; i++)
            {
                pair<int, int> newp = make_pair(t.fi + dr[i], t.se + dc[i]);
                if(newp.fi <= r && newp.fi >= 1 && newp.se <= c && newp.se >= 1 && st.count(newp) && !vis.count(newp))
                {
                    q.push(newp);
                    vis.insert(newp);
                    fen += 4;
                    if(vis.count(make_pair(newp.fi - 1, newp.se))) fen -= 2;
                    if(vis.count(make_pair(newp.fi + 1, newp.se))) fen -= 2;
                    if(vis.count(make_pair(newp.fi, newp.se + 1))) fen -= 2;
                    if(vis.count(make_pair(newp.fi, newp.se - 1))) fen -= 2;
                }
            }
        }
        ans = max(ans, fen);
    }

    cout << ans << endl;

    // cout << endl; for(auto u : vis) cout << u.fi << " " << u.se << endl;
}

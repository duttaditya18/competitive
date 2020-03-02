#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t; cin >> t;

    while(t--)
    {
        int h, w, q, x, y, z; cin >> h >> w >> q;

        if(h == 1)
        {
            int a[w + 1] = {};
            for(int i = 1; i <= w; i++) cin >> a[i];

            while(q--)
            {
                cin >> x >> y >> z;
                queue<int> q;
                int ans = 0;

                if(z <= a[y])
                {
                    cout << 0 << "\n";
                    continue;
                }

                int vis[w + 1] = {};
                q.push(y);
                vis[y] = 1;

                while(!q.empty())
                {
                    int t = q.front(); q.pop();
                    // cout << t << endl;
                    ans++;

                    if(t - 1 >= 1 && !vis[t - 1] && a[t - 1] < z)
                    {
                        q.push(t - 1);
                        vis[t - 1] = 1;
                    }
                    if(t + 1 <= w && !vis[t + 1] && a[t + 1] < z)
                    {
                        q.push(t + 1);
                        vis[t + 1] = 1;
                    }
                }
                cout << ans << "\n";
            }
            continue;
        }

        int k;
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                cin >> k;

        while(q--)
        {
            cin >> x >> y >> z;
            if(z > k) cout << (1ll* h * w);
            else cout << 0;
            cout << "\n";
        }
    }
    return 0;
}

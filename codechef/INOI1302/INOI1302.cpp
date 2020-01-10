#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int x, p, n, k; cin >> n >> k;

    vector<int> a[n];

    for(int i = 0; i < n; i++)
    {
        cin >> p;
        for(int j = 0; j < p; j++)
        {
            cin >> x;
            a[i].push_back(x);
        }
        sort(a[i].begin(), a[i].end());
    }

    // for(auto u : a) { for(auto g : u) cout << g << " "; cout << endl; }

    queue<int> q;
    int vis[n] = {};

    q.push(0);
    vis[0] = 1;

    int ans = 0;

    while(!q.empty())
    {
        int t = q.front();
        // cout << t << endl;
        ans++;
        q.pop();

        for(int i = 0; i < n; i++)
        {
            if(vis[i] || i == t) continue;

            int cm = 0;
            for(int j = 0, sx = a[t].size(); j < sx; j++)
            {
                if(binary_search(a[i].begin(), a[i].end(), a[t][j])) cm++;
                if(cm >= k)
                {
                    vis[i] = 1;
                    q.push(i);
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}

#include <bits/stdc++.h>

using namespace std;

#define getchar getchar_unlocked

void fastscan(int &x)
{
    bool neg=false;
    register int c;
    x =0;
    c=getchar();
    if(c=='-')
    {
        neg = true;
        c=getchar();
    }
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *=-1;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;

    while(t--)
    {
        int n, m; cin >> n >> m;

        int a, b;

        vector<int> adj[n + 1];

        for(int i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int vis[n + 1] = {};

        long long odd = 0;
        long long eve = 0;

        for(int i = 1; i <= n; i++)
        {
            if(vis[i]) continue;

            queue<tuple<int, int>> q;
            long long pnt = 0;

            int el = 0;
            int la = INT_MIN;

            q.push(make_tuple(i, 1));
            vis[i] = 1;

            while(!q.empty())
            {
                int t = get<0>(q.front());
                int d = get<1>(q.front());
                q.pop();
                el++;
                pnt += d;
                la = max(la, t);

                for(auto u : adj[t])
                {
                    if(vis[u]) continue;
                    q.push(make_tuple(u, d + 1));
                    vis[u] = 1;
                }
            }

            if(el % 2)
            {
                queue<tuple<int, int>> qe;
                int v[n + 1] = {};
                pnt = 0;

                qe.push(make_tuple(la, 1));
                v[la] = 1;

                while(!qe.empty())
                {
                    int t = get<0>(qe.front());
                    int d = get<1>(qe.front());
                    pnt += d;
                    qe.pop();

                    for(auto u : adj[t])
                    {
                        if(v[u]) continue;
                        qe.push(make_tuple(u, d + 1));
                        v[u] = 1;
                    }
                }
                odd += pnt;
            }
            else eve += pnt;
        }
        cout << eve << " " << odd << "\n";
    }
}

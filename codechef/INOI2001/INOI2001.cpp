#include <bits/stdc++.h>

using namespace std;
#define MAXN 100010
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

int TC, t, el, sm, la, st, d, p, a, b, n, m;
long long pnt, odd, eve;
int vis[MAXN];
vector<int> adj[MAXN];
queue<int> q;
queue<tuple<int, int, int>> qu;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    fastscan(TC);

    while(TC--)
    {
        fastscan(n);
        fastscan(m);

        for(int i = 0; i < m; i++)
        {
            fastscan(a);
            fastscan(b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        odd = 0;
        eve = 0;

        for(int i = 1; i <= n; i++)
        {
            if(vis[i]) continue;

            el = 0;
            sm = INT_MAX;
            la = INT_MIN;

            q.push(i);
            vis[i] = 1;

            while(!q.empty())
            {
                t = q.front(); q.pop();
                el++;
                sm = min(sm, t);
                la = max(la, t);
                for(auto u : adj[t])
                {
                    if(vis[u]) continue;
                    q.push(u);
                    vis[u] = 1;
                }
            }

            if(el % 2) st = la;
            else st = sm;

            qu.push(make_tuple(st, 1, 0));
            pnt = 0;

            while(!qu.empty())
            {
                t = get<0>(qu.front());
                d = get<1>(qu.front());
                p = get<2>(qu.front());
                qu.pop();
                pnt += d;
                for(auto u : adj[t])
                {
                    if(u == p) continue;
                    qu.push(make_tuple(u, d + 1, t));
                }
            }

            if(el % 2) odd += pnt;
            else eve += pnt;
        }
        cout << eve << " " << odd << "\n";
        for(int i = 1; i <= n; i++)
        {
            adj[i].clear();
            vis[i] = 0;
        }
    }
    return 0;
}

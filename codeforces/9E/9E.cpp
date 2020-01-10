#include <bits/stdc++.h>

using namespace std;

bool comp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if(p1.first != p2.first) p1.first < p2.first;
    else p2.second < p2.second;
}

int main(void)
{
    int n, m; cin >> n >> m;

    int adj[n + 1][n + 1] = {};
    vector<int> adjl[n + 1];
    int deg[n + 1] = {};

    int x, y;

    bool f = true;

    for(int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        adj[x][y] = adj[y][x] = 1;
        adjl[x].push_back(y);
        adjl[y].push_back(x);

        deg[x]++; deg[y]++;
        if(deg[x] > 2 || deg[y] > 2) f = false;
    }
    if(m > n || !f)
    {
        cout << "NO\n";
        return 0;
    }

    if(m == n)
    {
        int visited[n + 1] = {};
        visited[1] = 1;
        queue<int> q;
        q.push(1);

        while(!q.empty())
        {
            int t = q.front();
            q.pop();

            for(auto u : adjl[t])
            {
                if(!visited[u])
                {
                    q.push(u);
                    visited[u] = 1;
                }
            }
        }

        f = true;

        for(int i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                f = false;
                break;
            }
        }

        if(f)
        {
            cout << "YES\n0\n";
            return 0;
        }
        else
        {
            cout << "NO\n";
            return 0;
        }
    }

    int visited[n + 1] = {};
    int comp[n + 1] = {};
    int parn[n + 1] = {};
    int c = 1;
    for(int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        int locvi[n + 1] = {};

        visited[i] = 1;
        locvi[i] = 1;
        parn[i] = 0;
        comp[i] = c;

        queue<int> q;
        q.push(i);

        f = true;

        while(!q.empty() && f)
        {
            int t = q.front();
            q.pop();

            for(auto u : adjl[t])
            {
                if(locvi[u] && u != parn[t])
                {
                    f = false;
                    break;
                }
                if(!visited[u])
                {
                    visited[u] = 1;
                    locvi[u] = 1;
                    parn[u] = t;
                    comp[u] = c;
                    q.push(u);
                }
            }
        }

        if(!f)
        {
            cout << "NO\n";
            return 0;
        }
        c++;
    }

    vector<pair<int, int>> v;

    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(deg[i] < 2 && deg[j] < 2 && comp[i] != comp[j] && !adj[i][j])
            {
                // cout << i << " " << j << " " << deg[i] << " " << deg[j] << " " << comp[i] << " " << comp[j] << " " << adj[i][j] << endl;
                deg[i]++;
                deg[j]++;
                adj[i][j] = 1;
                adj[j][i] = 1;
                v.push_back(make_pair(i, j));
            }
        }
    }

    int fx, lx;
    f = true;
    for(int i = 1; i <= n; i++)
    {
        if(deg[i] == 1)
        {
            if(f)
            {
                f = false;
                fx = i;
            }
            else
            {
                lx = i;
            }
        }
        else if(deg[i] == 0)
        {
            f = false;
            fx = i;
            lx = i;
            deg[i] += 2;
        }
    }
    v.push_back(make_pair(fx, lx));

    cout << "YES\n" << v.size() << "\n";
    for(auto u : v)
    {
        cout << u.first << " " << u.second << "\n";
    }
}

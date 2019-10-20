#include <bits/stdc++.h>

using namespace std;

#define MAX_CON 100010

vector<int> adj[MAX_CON];
int colors[MAX_CON][11] = {};

void color(int v, int d, int c)
{
    if(colors[v][d]) return;

    colors[v][d] = c;

    if(d == 0) return;

    color(v, d - 1, c);
    for(auto u : adj[v])
    {
        color(u, d - 1, c);
    }
}

int main(void)
{
    int n, m;
    cin >> n >> m;

    int a, b;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int q;
    cin >> q;

    int v[q], d[q], c[q];

    for(int i = 0; i < q; i++)
    {
        cin >> v[i] >> d[i] >> c[i];
    }

    for(int i = q - 1; i >= 0; i--)
    {
        color(v[i], d[i], c[i]);
    }

    for(int i = 1; i <= n; i++)
    {
        cout << colors[i][0] << "\n";
    }
    return 0;
}

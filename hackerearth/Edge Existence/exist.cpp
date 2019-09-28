#include <bits/stdc++.h>

using namespace std;

int adj[2000][2000];

int main(void)
{
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    int q;
    cin >> q;
    while(q--)
    {
        cin >> a >> b;
        cout << (adj[a][b] ? "YES" : "NO") << endl;
    }
}

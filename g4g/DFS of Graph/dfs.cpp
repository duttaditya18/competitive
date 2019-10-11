#include <bits/stdc++.h>

using namespace std;

bool visited[200];
vector<int> adj[200];

void dfs(int s)
{
    cout << s << " ";
    if(visited[s]) return;
    visited[s] = true;
    for(auto u: adj[s])
        dfs(u);
}

int main(void)
{
    int q;
    cin >> q;
    while(q--)
    {
        int n, e;
        cin >> n >> e;

        int x, y;
        for(int i = 0; i < 200; i++) adj[i].clear();

        for(int i = 0; i < e; i++)
        {
            cin >> x >> y;
            adj[x].push_back(y);
        }
        memset(visited, 0, sizeof(bool) * 200);
        dfs(0);
        cout << endl;
    }
    return 0;
}

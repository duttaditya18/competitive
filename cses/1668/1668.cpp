#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    int a, b;

    vector<int> adj[n + 1];
    int visited[n + 1] = {};

    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int t;

    for(int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        queue<int> q;
        q.push(i);
        visited[i] = 1;

        while(!q.empty())
        {
            t = q.front();
            q.pop();

            for(auto u : adj[t])
            {
                if(visited[u])
                {
                    if(visited[u] == visited[t])
                    {
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                }
                else
                {
                    visited[u] = (visited[t] == 1 ? 2 : 1);
                    q.push(u);
                }
            }
        }
    }


    for(int i = 1; i <= n; i++) cout << visited[i] << " ";
    cout << "\n";
    return 0;
}

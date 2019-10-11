#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    int visited[n + 1] = {};

    int a, b;

    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    visited[1] = -1;
    int t;

    while(!q.empty())
    {
        t = q.front();
        q.pop();


        if(t == n)
        {
            vector<int> l;
            while(t != -1)
            {
                l.push_back(t);
                t = visited[t];
            }
            reverse(l.begin(), l.end());
            cout << l.size() << "\n";
            for(auto u : l)
                cout << u << " ";
            cout << "\n";
            return 0;
        }

        for(auto u : adj[t])
        {
            if(!visited[u])
            {
                visited[u] = t;
                q.push(u);
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}

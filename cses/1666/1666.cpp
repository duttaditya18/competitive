#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    int a, b;
    bool visited[n + 1] = {};
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int cnt = 0;
    vector<tuple<int, int>> x;

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            queue<int> q;
            q.push(i);

            int t;

            while(!q.empty())
            {
                t = q.front();
                q.pop();

                for(auto u : adj[t])
                {
                    if(!visited[u])
                    {
                        q.push(u);
                        visited[u] = true;
                    }
                }
            }


            if(i == 1) continue;
            cnt++;
            x.push_back(make_tuple(i - 1, i));
        }
    }

    //for(int i = 0; i <= n; i++) cout << i << " : " << visited[i] << endl;
    cout << cnt << "\n";
    for(auto u : x)
        cout << get<0>(u) << " " << get<1>(u) << "\n";
}

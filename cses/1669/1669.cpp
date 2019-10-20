// Wrong Implementation

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    int a, b, c;

    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // for(int i = 0; i < adj[1].size(); i++) cout << adj[1][i] << endl;

    for(int i = 1; i < n; i++)
    {
        bool visited[n + 1] = {};
        int prv[n + 1] = {};

        // node, distance
        queue<tuple<int, int>> q;
        q.push(make_tuple(i, 0));


        visited[i] = true;
        prv[i] = 0;

        while(!q.empty())
        {
            a = get<0>(q.front());
            b = get<1>(q.front());
            q.pop();

            for(auto u : adj[a])
            {
                if(u == i)
                {
                    if(b >= 3)
                    {
                        cout << i << endl;
                        vector<int> cnt;
                        cout << b + 1 << endl;
                        cnt.push_back(i);
                        cnt.push_back(a);
                        for(int i = 0; i <= b; i++)
                        {
                            cnt.push_back(prv[a]);
                            a = prv[a];
                        }

                        reverse(cnt.begin(), cnt.end());

                        for(vector<int>::iterator itr = cnt.begin(); itr != cnt.end(); itr++)
                        {
                            cout << *itr << " ";
                        }
                        cout << "\n";
                        return 0;
                    }
                }
                if(visited[u]) continue;
                q.push(make_tuple(u, b + 1));
                prv[u] = a;
            }
        }

    }
    cout << "IMPOSSIBLE\n";
    return 0;
}

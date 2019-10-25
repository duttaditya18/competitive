#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector<tuple<int, int>> v;
    vector<int> adj[n + 1];

    int a, b;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        v.push_back(make_tuple(a, b));
    }

    int c[n + 1], clr;
    for(int i = 1; i <= n; i++)
    {
        cin >> clr;
        c[i] = clr;
    }

    // node-1 and node-2
    int x[2];
    int allSame = true;

    for(int i = 0; i < n - 1; i++)
    {
        x[0] = get<0>(v[i]);
        x[1] = get<1>(v[i]);

        if(c[x[0]] == c[x[1]]) continue;
        else
        {
            //cout << x[0] << " " << x[1] << endl;
            allSame = false;

            for(int i = 0; i < 2; i++)
            {
                bool ans = true;

                queue<tuple<int, int>> q;
                bool visited[n + 1] = {};

                visited[x[i]] = true;

                for(auto u : adj[x[i]])
                {
                    if(visited[u]) continue;
                    q.push(make_tuple(u, c[u]));
                    visited[u] = true;
                }

                while(!q.empty())
                {
                    int t = get<0>(q.front());
                    int clr = get<1>(q.front());
                    //cout << t << " " << clr << " " << c[t] << endl;

                    q.pop();

                    if(clr != c[t])
                    {
                        ans = false;
                        break;
                    }

                    for(auto u : adj[t])
                    {
                        if(visited[u]) continue;

                        q.push(make_tuple(u, clr));
                        visited[u] = true;
                    }
                }

                //  cout << ans << endl;
                if(ans)
                {
                    cout << "YES\n" << x[i] << "\n";
                    return 0;
                }

            }
            break;
        }
    }

    if(allSame)
    {
        cout << "YES\n" << x[0] << "\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}

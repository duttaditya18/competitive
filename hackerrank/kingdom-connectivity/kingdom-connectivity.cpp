#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m; cin >> n >> m;

    vector<int> adj[n + 1];

    int a, b;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int> vi(n + 1, 0);
    vector<int> os(n + 1, 0);
    stack<int> s;

    s.push(1);

    bool f = 1;

    while(!s.empty() && f)
    {
        int t = s.top();

        if(!vi[t])
        {
            vi[t] = 1;
            os[t] = 1;
        }
        else
        {
            os[t] = 0;
            s.pop();
        }

        for(auto u : adj[t])
        {
            if(!vi[u])
            {
                s.push(u);
            }
            else if(os[u])
            {
                f = false;
                break;
            }
        }
    }

    if(f)
    {
        queue<int> q;
        q.push(1);

        int ans = 0;

        while(!q.empty())
        {
            int t = q.front();
            q.pop();

            if(t == n) ans++;

            for(auto u : adj[t])
            {
                q.push(u);
            }
        }

        cout << ans << endl;
    }
    else
    {
        cout << "INFINITE PATHS\n";
        return 0;
    }
}

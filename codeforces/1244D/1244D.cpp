#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int c[3][n];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> c[i][j];
            //cout << c[i][j] << " ";
        }
    }

    vector<int> adj[n + 1];
    int a, b;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int child = 0;
    bool visited[n + 1] = {};
    bool isChain = true;
    int en = 0;

    queue<int> q;
    q.push(1);
    visited[1] = true;
    int t;
    while(!q.empty())
    {
        t = q.front();
        //cout << t << endl;
        child = 0;
        q.pop();
        for(auto u : adj[t])
        {
            //cout << u << endl;
            child++;
            if(!visited[u])
            {
                visited[u] = true;
                q.push(u);
            }
        }
        if(child > 2)
        {
            isChain = false;
        }
        if(child == 1)
        {
            en = t;
        }
    }

    if(!isChain)
    {
        cout << -1;
    }
    else if(isChain)
    {
        bool visited[n + 1] = {};
        int child[n + 1] = {};

        queue<int> q;
        q.push(en);
        visited[en] = true;

        int t;
        while(!q.empty())
        {
            t = q.front();
            q.pop();
            for(auto u : adj[t])
            {
                if(!visited[u])
                {
                    child[t] = u;
                    visited[u] = true;
                    q.push(u);
                }
            }
        }

        /*int x = 0;
        int curNode = en;
        while(x != n)
        {
            cout << curNode << " ";
            curNode = child[curNode];
            x++;
        }*/

        int combi[6][3] = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
        long long minSum = LLONG_MAX;

        int color[n + 1] = {};
        int colorAns[n + 1] = {};

        for(int i = 0; i < 6; i++)
        {
            int x = 0;
            long long curSum = 0;
            int curNode = en;
            while(x != n)
            {
                for(int j = 0; j < 3 and x != n; j++)
                {
                    color[curNode] = combi[i][j];
                    curSum += 1ll*c[combi[i][j] - 1][curNode - 1];
                    curNode = child[curNode];
                    x++;
                }
            }
            if(curSum < minSum)
            {
                minSum = curSum;
                memcpy(colorAns, color, sizeof(color));
            }
        }

        cout << minSum << "\n";
        for(int i = 1; i <= n; i++)
        {
            cout << colorAns[i] << " ";
        }
    }
    cout << "\n";
}

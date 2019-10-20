#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> adj[n + 1];

        int children[n + 1] = {};

        int a, b;

        for(int i = 0; i < n - 1; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            children[a]++;
        }

        // for(int i = 0; i < n + 1; i++) cout << children[i] << endl;

        int selected[n + 1] = {};
        int childselect[n + 1] = {};
        int distance[n + 1] = {};

        distance[1] = 1;

        queue <int> q;
        q.push(1);

        long long ans = 0;1
7 2
1 2
1 3
2 4
2 5
3 6
3 7
        long long finans = 0;

        for(int i = 0; i < k; i++)
        {
            cout << ans << endl;
            ans = 0;
            while(!q.empty())
            {
                int s = q.front();
                q.pop();

                bool flag = false;
                if(selected[s])
                {
                    if(ans + children[s] - 1 - childselect[s] > ans)
                    {
                        flag = true;
                        ans = ans + children[s] - 1 - childselect[s];
                        selected[s] = false;
                    }
                }
                else
                {
                    if(ans + children[s] - childselect[s] > ans)
                    {
                        flag = true;
                        ans = ans + children[s] - childselect[s];
                    }
                }

                for(auto u : adj[s])
                {
                    if(flag and !selected[u]) selected[u] = true;
                    distance[u] = distance[s] + 1;
                    q.push(u);
                }
            }
            finans += ans;
        }

        cout << finans << "\n";

         for(int i = 0; i < n + 1; i++) cout << selected[i] << endl;
    }
    return 0;
}

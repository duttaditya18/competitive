#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

int main(void)
{
    int n, m, k; cin >> n >> m >> k;

    int a[n + 1][m + 1] = {};
    char c;

    pair<int, int> st;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> c;
            if(c == '.')
            {
                a[i][j] = 1;
                st.fi = i;
                st.se = j;
            }
        }
    }

    queue<pair<int, int>> q;
    int vis[n + 1][m + 1] = {};
    vector<pair<int, int>> v;

    q.push(st);
    vis[st.fi][st.se] = 1;
    v.push_back(st);

    int dn[] = {1, -1, 0, 0};
    int dm[] = {0, 0, 1, -1};

    while(!q.empty())
    {
        pair<int, int> t = q.front();
        // cout << "(" << t.fi << ", " << t.se << ")" << endl;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nn = t.fi + dn[i];
            int nm = t.se + dm[i];
            if(nn >= 1 && nn <= n && nm >= 1 && nm <= m)
                if(!vis[nn][nm] && a[nn][nm])
                {
                    q.push({nn, nm});
                    vis[nn][nm] = 1;
                    v.push_back({nn, nm});
                }
        }
    }

    for(int i = v.size() - 1; i >= v.size() - k; i--)
    {
        // cout << "(" << v[i].fi << ", " << v[i].se << ")" << endl;
        a[v[i].fi][v[i].se] = 2;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(!a[i][j]) cout << "#";
            else if(a[i][j] == 1) cout << ".";
            else cout << "X";
        }
        cout << endl;
    }
}

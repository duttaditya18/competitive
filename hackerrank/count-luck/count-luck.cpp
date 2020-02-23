#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

int main(void)
{
    int t; cin >> t;

    while(t--)
    {
        int n, m; cin >> n >> m;

        char c;
        int a[n][m] = {};
        pair<int, int> st;
        pair<int, int> en;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> c;
                if(c != 'X') a[i][j] = 1;
                if(c == 'M')
                {
                    st.fi = i;
                    st.se = j;
                }
                if(c == '*')
                {
                    en.fi = i;
                    en.se = j;
                }
            }
        }

        int gu;
        cin >> gu;

        queue<tuple<pair<int, int>, int>> q;
        int vis[n][m] = {};

        q.push(make_tuple(st, 0));
        vis[st.fi][st.se] = 1;

        int dn[] = {1, -1, 0, 0};
        int dm[] = {0, 0, 1, -1};

        int ans;

        while(!q.empty())
        {
            pair<int, int> t = get<0>(q.front());
            int d = get<1>(q.front());
            q.pop();

            // cout << "(" << t.fi << " " << t.se << ") " << d << endl;

            if(t == en)
            {
                ans = d;
                break;
            }

            int c = 0;

            for(int i = 0; i < 4; i++)
            {
                int nn = t.fi + dn[i];
                int nm = t.se + dm[i];

                if(nn < n && nn >= 0 && nm < m && nm >= 0)
                    if(!vis[nn][nm] && a[nn][nm]) c++;
            }

            int nd = d;
            if(c > 1) nd++;

            for(int i = 0; i < 4; i++)
            {
                int nn = t.fi + dn[i];
                int nm = t.se + dm[i];
                if(nn < n && nn >= 0 && nm < m && nm >= 0)
                    if(!vis[nn][nm] && a[nn][nm])
                    {
                        q.push(make_tuple(make_pair(nn, nm), nd));
                        vis[nn][nm] = 1;
                    }
            }
        }
        cout << (ans == gu ? "Impressed" : "Oops!") << endl;
    }
}

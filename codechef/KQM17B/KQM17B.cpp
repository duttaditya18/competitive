#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    int ns, ms;

    int c[n + 1][m + 1] = {};

    vector<tuple<int, int>> v;

    char x;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> x;
            if(x == '.') c[i][j] = 1;
            else if(x == '#') c[i][j] = 0;
            else if(x == 'X')
            {
                ns = i;
                ms = j;
                c[i][j] = 1;
            }
            else if(x == 'K')
            {
                c[i][j] = 1;
                v.push_back(make_tuple(i, j));
            }
        }
    }

    int visited[n + 1][m + 1] = {};

    queue<tuple<int, int>> q;
    q.push(make_tuple(ns, ms));

    int nt, mt;

    while(!q.empty())
    {
        nt = get<0>(q.front());
        mt = get<1>(q.front());
        q.pop();

        if(c[nt + 1][mt] && nt + 1 <= n && !visited[nt + 1][mt])
        {
            q.push(make_tuple(nt + 1, mt));
            visited[nt + 1][mt] = 1;
        }
        if(c[nt - 1][mt] && nt - 1 >= 1 && !visited[nt - 1][mt])
        {
            q.push(make_tuple(nt - 1, mt));
            visited[nt - 1][mt] = 1;
        }
        if(c[nt][mt + 1] && mt + 1 <= m && !visited[nt][mt + 1])
        {
            q.push(make_tuple(nt, mt + 1));
            visited[nt][mt + 1] = 1;
        }
        if(c[nt][mt - 1] && mt - 1 >= 1 && !visited[nt][mt - 1])
        {
            q.push(make_tuple(nt, mt - 1));
            visited[nt][mt - 1] = 1;
        }
    }

    for(auto u : v)
    {
        if(!visited[get<0>(u)][get<1>(u)])
        {
            cout << "No\n";
            return 0;
        }
    }

    /*for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            cout << visited[i][j];
        }
        cout << endl;
    }*/

    cout << "Yes\n";
    return 0;
}

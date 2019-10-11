// Useless <3

#include <bits/stdc++.h>

using namespace std;

int n, m;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    bool pos[n][m] = {};
    char c;

    int xi, yi, xf, yf;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> c;
            if(c == '.') pos[i][j] = 1;
            if(c == 'A')
            {
                xi = i;
                yi = j;
            }
            if(c == 'B')
            {
                pos[i][j] = 1;
                xf = i;
                yf = j;
            }
        }
    }

    bool visited[n][m] = {};

    queue<tuple<int, int, string>> q;

    int x, y;
    string s;

    q.push(make_tuple(xi, yi, ""));
    visited[xi][yi] = true;

    string ans = "F";

    while(!q.empty())
    {
        tie(x, y , s) = q.front();

        q.pop();
        //cout << x << " " << y << " " << s << endl;

        if(x == xf and y == yf)
        {
            ans = s;
            break;
        }

        if(pos[x - 1][y] and !visited[x - 1][y])
        {
            if(x - 1>= 0 and y >= 0 and x - 1 <= n - 1 and y <= m - 1)
            {
                visited[x - 1][y] = true;
                q.push(make_tuple(x - 1, y, s + "U"));
            }
        }
        if(pos[x + 1][y] and !visited[x + 1][y])
        {
            if(x + 1 >= 0 and y >= 0 and x + 1 <= n - 1 and y <= m - 1)
            {
                visited[x + 1][y] = true;
                q.push(make_tuple(x + 1, y, s + "D"));
            }
        }
        if(pos[x][y - 1] and !visited[x][y - 1])
        {
            if(x >= 0 and y - 1 >= 0 and x <= n - 1 and y - 1 <= m - 1)
            {
                visited[x][y - 1] = true;
                q.push(make_tuple(x, y - 1, s + "L"));
            }
        }
        if(pos[x][y + 1] and !visited[x][y + 1])
        {
            if(x >= 0 and y + 1 >= 0 and x <= n - 1 and y + 1 <= m - 1)
            {
                visited[x][y + 1] = true;
                q.push(make_tuple(x, y + 1, s + "R"));
            }
        }
    }

    if(ans == "F") cout << "NO";
    else
    {
        cout << "YES" << "\n";
        cout << ans.size() << "\n";
        cout << ans;
    }
    cout << "\n";

    //for(int i = 0; i < n; i++) { for(int j = 0; j < m; j++) cout << pos[i][j]; cout << endl; }
}

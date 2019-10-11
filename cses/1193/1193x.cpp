// Strings Useless <3

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

    // 1 - Up, 2 - Down, 3 - Left, 4 - Right, 5 - Original Position
    int visited[n][m] = {};

    queue<tuple<int, int>> q;

    int x, y;

    q.push(make_tuple(xi, yi));
    visited[xi][yi] = 5;

    while(!q.empty())
    {
        tie(x, y) = q.front();

        q.pop();
        //cout << x << " " << y << " " << s << endl;

        if(x == xf and y == yf)
        {
            string p = "";
            while(visited[x][y] != 5)
            {
                if(visited[x][y] == 1)
                {
                    p += "U";
                    x++;
                }
                else if(visited[x][y] == 2)
                {
                    p += "D";
                    x--;
                }
                else if(visited[x][y] == 3)
                {
                    p += "L";
                    y++;
                }
                else if(visited[x][y] == 4)
                {
                    p += "R";
                    y--;
                }
            }
            reverse(p.begin(), p.end());
            cout << "YES\n";
            cout << p.size() << "\n";
            cout << p << "\n";
            return 0;
        }

        if(pos[x - 1][y] and !visited[x - 1][y])
        {
            if(x - 1>= 0 and y >= 0 and x - 1 <= n - 1 and y <= m - 1)
            {
                visited[x - 1][y] = 1;
                q.push(make_tuple(x - 1, y));
            }
        }
        if(pos[x + 1][y] and !visited[x + 1][y])
        {
            if(x + 1 >= 0 and y >= 0 and x + 1 <= n - 1 and y <= m - 1)
            {
                visited[x + 1][y] = 2;
                q.push(make_tuple(x + 1, y));
            }
        }
        if(pos[x][y - 1] and !visited[x][y - 1])
        {
            if(x >= 0 and y - 1 >= 0 and x <= n - 1 and y - 1 <= m - 1)
            {
                visited[x][y - 1] = 3;
                q.push(make_tuple(x, y - 1));
            }
        }
        if(pos[x][y + 1] and !visited[x][y + 1])
        {
            if(x >= 0 and y + 1 >= 0 and x <= n - 1 and y + 1 <= m - 1)
            {
                visited[x][y + 1] = 4;
                q.push(make_tuple(x, y + 1));
            }
        }
    }

    cout << "NO\n";
    return 0;

    //for(int i = 0; i < n; i++) { for(int j = 0; j < m; j++) cout << pos[i][j]; cout << endl; }
}

#include <bits/stdc++.h>

using namespace std;

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

int main(void)
{
    int t;
    cin >> t;

    int ans;

    while(t--)
    {
        ans = INT_MAX;
        int n = 8, m = 8;
        char chxi;
        int xi, yi;
        cin >> chxi >> yi;
        xi = chxi - 'a' + 1;
        char chxf;
        int xf, yf;
        cin >> chxf >> yf;
        xf = chxf - 'a' + 1;

        bool visited[n + 1][m + 1] = {};
        queue<tuple<int, int, int>> q;

        q.push(make_tuple(xi, yi, 0));
        visited[xi][yi] = true;

        tuple<int, int, int> t;
        int x, y, d;

        while(!q.empty())
        {
            t = q.front(); q.pop();

            //cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
            if(get<0>(t) == xf and get<1>(t) == yf)
            {
                ans = get<2>(t);
                break;
            }

            for(int i = 0; i < 8; i++)
            {
                x = get<0>(t) + dx[i];
                y = get<1>(t) + dy[i];
                d = get<2>(t) + 1;


                if(!visited[x][y])
                {
                    if(x <= n and y <= m and x >= 1 and y >= 1)
                    {
                        visited[x][y] = true;
                        q.push(make_tuple(x, y, d));
                    }
                }
            }
        }
        cout << (ans != INT_MAX ? ans : -1) << endl;
    }
}

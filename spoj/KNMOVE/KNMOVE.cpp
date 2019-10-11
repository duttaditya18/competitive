#include <bits/stdc++.h>

using namespace std;

#define INF 100000000

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

int moves[1001][1001] = {};

int main(void)
{
    int f;
    cin >> f;

    // Initialize
    for(int i = 0; i < 1001; i++)
        for(int j = 0; j < 1001; j++)
            moves[i][j] = INF;

    int n = 1000, m = 1000;

    queue<tuple<int, int>> q;

    q.push(make_tuple(1, 1));
    moves[1][1] = 0;

    tuple<int, int> t;
    int x, y, tmpX, tmpY;

    // Precompute
    while(!q.empty())
    {
        t = q.front(); q.pop();
        x = get<0>(t);
        y = get<1>(t);

        //cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;

        for(int i = 0; i < 8; i++)
        {
            tmpX = x + dx[i];
            tmpY = y + dy[i];

            if(moves[tmpX][tmpY] == INF)
            {
                if(tmpX <= 1000 and tmpY <= 1000 and tmpX >= 1 and tmpY >= 1)
                {
                    moves[tmpX][tmpY] = moves[x][y] + 1;
                    moves[tmpY][tmpX] = moves[tmpX][tmpY];
                    q.push(make_tuple(tmpX, tmpY));
                }
            }
        }
    }

    while(f--)
    {
        cin >> x >> y;
        cout << moves[x][y] << endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

int main(void)
{
    int n, m;
    cin >> n >> m;
    bool pos[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> pos[i][j];

    //for(int i = 0; i < n; i++) { for(int j = 0; j < m; j++) cout << pos[i][j]; cout << endl; }

    int x, y;
    cin >> x >> y;

    int cnt = 0;
    int tmpX, tmpY;

    for(int i = 0; i < 8; i++)
    {
        tmpX = x + dx[i] - 1;
        tmpY = y + dy[i] - 1;
        //cout << tmpX << " " << tmpY << endl;
        if(tmpX >= 0 and tmpY >= 0 and tmpX < n and tmpY < m)
        {
            if(!pos[tmpX][tmpY]) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

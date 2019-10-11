#include <bits/stdc++.h>

using namespace std;

int n, m;
int room[1000][1000];
int cnt = 0;
bool visited[1000][1000];

void travis(int i, int j);

int main(void)
{
    cin >> n >> m;
    char c;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> c;
            if(c == '.') room[i][j] = 1;
        }
    }

    //for(int i = 0; i < n; i++) { for(int j = 0; j < m; j++) { cout << room[i][j]; } cout << endl; }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(room[i][j])
            {
                if(!visited[i][j])
                {
                    //cout << "(" << i << ", " << j << ")" << endl;
                    cnt++;
                    travis(i, j);
                }
            }
        }
    }

    cout << cnt << endl;

    return 0;
}

void travis(int i, int j)
{
    visited[i][j] = true;
    if(i + 1 < n)
        if(room[i + 1][j] && !visited[i + 1][j])
            travis(i + 1, j);
    if(j + 1 < m)
        if(room[i][j + 1] && !visited[i][j + 1])
            travis(i, j + 1);
    if(i - 1 >= 0)
        if(room[i - 1][j] && !visited[i - 1][j])
            travis(i - 1, j);
    if(j - 1 >= 0)
        if(room[i][j - 1] && !visited[i][j - 1])
            travis(i, j - 1);
}

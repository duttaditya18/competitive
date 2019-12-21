#include <bits/stdc++.h>

using namespace std;
#define INF 1000000000000

int main(void)
{
    int v, e; cin >> v >> e;

    long long dist[v + 1][v + 1] = {};

    for(int i = 0; i <= v; i++)
    {
        for(int j = 0; j <= v; j++)
        {
            dist[i][j] = INF;
        }
    }

    int x, y, z;

    for(int i = 1; i <= e; i++)
    {
        cin >> x >> y >> z;
        dist[x][y] = z;
        dist[y][x] = z;
    }

    for(int i = 1; i <= v; i++)
    {
        dist[i][i] = 0;
    }

    // for(int i = 1; i <= v; i++) { for(int j = 1; j <= v; j++) { cout << dist[i][j] << " "; } cout << endl; }

    for(int k = 1; k <= v; k++)
    {
        for(int i = 1; i <= v; i++)
        {
            for(int j = 1; j <= v; j++)
            {
                if(dist[i][k] == INF || dist[k][j] == INF) continue;
                // cout << i << " " << j << " " << k << endl;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // for(int i = 1; i <= v; i++) { for(int j = 1; j <= v; j++) { cout << dist[i][j] << " "; } cout << endl; }

    long long ma = 0;

    for(int i = 1; i <= v; i++)
    {
        for(int j = 1; j <= v; j++)
        {
            if(i == j) continue;
            ma = max(ma, dist[i][j]);
        }
    }

    cout << ma << endl;
}

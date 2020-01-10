// IDK why WA

#include <bits/stdc++.h>

using namespace std;

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

bool isLegal(int x, int y, int n)
{
    if(x >= 0 and y >= 0 and x < n and y < n) return true;
    return false;
}

double knightProbability(int N, int K, int r, int c)
{
    int inside = 0;
    int outside = 0;

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(r, c, 0));

    tuple<int, int, int> t;
    int x, y, d;

    while(!q.empty())
    {
        t = q.front();
        q.pop();
        x = get<0>(t);
        y = get<1>(t);
        d = get<2>(t);

        if(!isLegal(x, y, N))
        {
            outside++;
            continue;
        }
        else if(d == K) inside++;

        if(d > K) break;

        for(int i = 0; i < 8; i++)
        {
            int tempX = x + dx[i];
            int tempY = y + dy[i];
            int tempD = d + 1;
            if(tempD <= K)
            {
                q.push(make_tuple(tempX, tempY, tempD));
            }
        }
    }

    cout << inside << " " << outside << "\n";
    return ((1.0 * inside) / (inside + outside));
}

int main(void)
{
    int n, k, r, c;
    // cin >> n >> k >> r >> c;

    n = 3, k = 1, r = 0, c = 0;

    cout << knightProbability(n, k, r, c) << "\n";
}

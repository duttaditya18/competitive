/*
5 10 10
1 1 1
1 2 1
2 1 1
2 2 1
3 3 1
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, c;
    cin >> n >> q >> c;

    int a[11][101][101] = {};

    // x coordinate, y coordinate, inital brightness of star
    int x, y, s;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y >> s;
        a[s][x][y]++;
    }

    for(s = 0; s <= 10; s++)
    {
        for(x = 1; x <= 100; x++)
        {
            for(y = 1; y <= 100; y++)
            {
                a[s][x][y] = a[s][x][y] + a[s][x - 1][y] + a[s][x][y - 1] - a[s][x - 1][y - 1];
            }
        }
    }

    //for(x = 1; x <= 10; x++) { for(y = 1; y <= 10; y++) cout << a[1][x][y] << " "; cout << endl; }

    int cursm, curmlt, ans;
    int t, x1, y1, x2, y2;

    for(int i = 0; i < q; i++)
    {
        ans = 0;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        for(s = 0; s <= 10; s++)
        {
            cursm = a[s][x2][y2] - a[s][x1 - 1][y2] - a[s][x2][y1 - 1] + a[s][x1 - 1][y1 - 1];
            curmlt = (s + t) % (c + 1);
            ans += cursm * curmlt;
        }
        cout << ans << endl;
    }
    return 0;
}

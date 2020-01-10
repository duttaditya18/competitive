#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    // N -> x, M -> y, N <= M
    int m, n;
    cin >> m >> n;

    int k; cin >> k;
    int x, y, r, b;

    int d[n + 2][m + 2] = {};

    for(int i = 0; i < k; i++)
    {
        cin >> x >> y >> r >> b;
        for(int j = 1; j <= n; j++)
        {
            if(abs(x - j) > r) continue;
            int ln = sqrt((r * r) - (j - x)*(j - x));

            d[j][max(y - ln, 1)] += b;
            d[j][min(m + 1, y + ln + 1)] -= b;
        }
    }

    int ma = 0, tot = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            d[i][j] += d[i][j - 1];
            if(d[i][j] > ma)
            {
                ma = d[i][j];
                tot = 1;
            }
            else if(d[i][j] == ma)
                tot++;
        }
    }

    cout << ma << endl << tot << endl;
}

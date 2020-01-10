#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second

int main(void)
{
    int r, c, d, k; cin >> r >> c >> d >> k;

    vector<pair<int, int>> v;
    vector<pair<int, int>> s;

    char x;
    int a[r + 2][c + 2] = {};

    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            cin >> x;
            if(x == 'M') v.push_back(make_pair(i, j));
            if(x == 'S')
            {
                for(int ix = max(1, i - d); ix <= min(r, i + d); ix++)
                {
                    a[ix][max(1, j - d)]++;
                    a[ix][min(c + 1, j + d + 1)]--;
                }
            }
        }
    }


    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            a[i][j] += a[i][j - 1];

    // for(int i = 1; i <= r + 1; i++) { for(int j = 1; j <= c + 1; j++) cout << a[i][j] << " "; cout << endl; }


    int ans = 0;
    for(auto u : v) if(a[u.fi][u.se] >= k) ans++;
    cout << ans << endl;
}

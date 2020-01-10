#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second

int main(void)
{
    int r, c, d, k; cin >> r >> c >> d >> k;

    vector<pair<int, int>> v;

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
                a[max(1, i - d)][max(1, j - d)]++;
                a[min(r + 1, i + d + 1)][max(1, j - d)]--;
                a[max(1, i - d)][min(c + 1, j + d + 1)]--;
                a[min(r + 1, i + d + 1)][min(c + 1, j + d + 1)]++;
            }
        }
    }


    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];

    // for(int i = 1; i <= r + 1; i++) { for(int j = 1; j <= c + 1; j++) cout << a[i][j] << " "; cout << endl; }


    int ans = 0;
    for(auto u : v) if(a[u.fi][u.se] >= k) ans++;
    cout << ans << endl;
}

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t; cin >> t;

    while(t--)
    {
        int n, m, k; cin >> n >> m >> k;

        int p[n + 1][m + 1] = {};
        int mi[n + 1][m + 1][k + 1] = {};
        int ma[n + 1][m + 1][k + 1] = {};

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> p[i][j];
                p[i][j] += p[i][j - 1];
                if(i == 1)
                {
                    for(int g = 0; g <= k; g++)
                    {
                        mi[i][j][g] = p[i][j];
                        ma[i][j][g] = p[i][j];
                    }
                }
            }
        }

        // cout << endl; for(int i = 1; i <= n; i++) { for(int j = 1; j <= m; j++) { cout << p[i][j] << " "; } cout << endl; }

        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                for(int g = 0; g <= k; g++)
                {
                    mi[i][j][g] = p[i][j] + mi[i - 1][j][g];
                    ma[i][j][g] = p[i][j] + ma[i - 1][j][g];
                    if(g < k && j > 0)
                    {
                        mi[i][j][g] = min(mi[i][j][g], p[i][j] + mi[i - 1][j - 1][g + 1]);
                    }
                    if(g < k && j > 1)
                    {
                        ma[i][j][g] = max(ma[i][j][g], p[i][j] + ma[i - 1][j - 1][g + 1]);
                    }
                }
            }
        }

        // cout << endl; for(int i = 1; i <= n; i++) { for(int j = 1; j <= m; j++) { cout << mi[i][j][0] << " "; } cout << endl; }

        // cout << endl; for(int i = 1; i <= n; i++) { for(int j = 1; j <= m; j++) { cout << ma[i][j][0] << " "; } cout << endl; }

        int ans = INT_MIN;

        for(int j = 0; j <= m - (k + 2); j++)
        {
            for(int z = j + k + 2; z <= m; z++)
            {
                ans = max(ans, ma[n][z][0] - mi[n][j][0]);
            }
        }
        cout << ans << endl;
    }
}

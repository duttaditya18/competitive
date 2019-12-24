#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;

    int prf[n + 1][n + 1] = {};

    int ans = INT_MIN;

    int mi[n + 1][n + 1] = {};

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> prf[i][j];
            prf[i][j] = prf[i][j] + prf[i][j - 1] + prf[i - 1][j] - prf[i - 1][j - 1];
            mi[i][j] = min({prf[i][j], mi[i - 1][j], mi[i][j - 1]});
            ans = max(ans, prf[i][j] - mi[i][j]);
        }
    }

    cout << ans << endl;

    for(int i = 0; i <= n; i++) { for(int j = 0; j <= n; j++) { cout << prf[i][j] << " "; } cout << endl; } cout << endl;
    for(int i = 0; i <= n; i++) { for(int j = 0; j <= n; j++) { cout << mi[i][j] << " "; } cout << endl; }

}

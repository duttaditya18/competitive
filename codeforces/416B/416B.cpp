#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int m, n;
    cin >> m >> n;

    int t[m + 1][n + 1] = {};

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> t[i][j];
            t[i][j] += max(t[i - 1][j], t[i][j - 1]);
            // cout << t[i][j] << " ";
        }
        // cout << "\n";
    }

    for(int i = 1; i <= m; i++) cout << t[i][n] << " ";
    cout << "\n";
}

#include <bits/stdc++.h>

#define MAXN 5010

bool dp[MAXN][MAXN];
int cn[MAXN][MAXN];

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    int n = s.size();

    for(int i = 1; i <= n; i++)
    {
        dp[i][i] = 1;
        dp[i + 1][i] = 1;
        cn[i][i] = 1;
    }

    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= n - i + 1; j++)
        {
            dp[j][j + i - 1] = (s[j - 1] == s[j + i - 2]) && (dp[j + 1][j + i - 2]);
            cn[j][j + i - 1] = dp[j][j + i - 1] + cn[j][j + i - 2] + cn[j + 1][j + i - 1] - cn[j + 1][j + i - 2];
        }
    }

    int x, y, q; cin >> q;
    while(q--)
    {
        cin >> x >> y;
        cout << cn[x][y] << "\n";
    }

    return 0;
}

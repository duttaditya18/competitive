#include <bits/stdc++.h>

using namespace std;

int dp[200][200], a[200], p, q;

int rec(int i, int j)
{
    cout << i << " " << j << endl;
    if(j - i <= 1) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mi = INT_MAX;

    for(int k = i + 1; k < j; k++)
    {
        mi = min(mi, rec(i, k) + rec(k, j));
    }
    dp[i][j] = mi + a[j] - a[i] - 3;
    if(i == 0) dp[i][j]++;
    if(j == q + 1) dp[i][j]++;
    dp[i][j] = max(dp[i][j], 0);
    return dp[i][j];
}

int main(void)
{
    int t;
    cin >> t;

    for(int f = 1; f <= t; f++)
    {
        cin >> p >> q;

        for(int i = 0; i <= q + 1; i++)
        {
            for(int j = 0; j <= q + 1; j++)
            {
                dp[i][j] = -1;
            }
        }

        a[0] = 0;
        for(int i = 1; i <= q; i++) cin >> a[i];
        a[q + 1] = p;

        // for(int i = 0; i <= q + 1; i++) cout << a[i] << " ";
        // cout << endl;

        cout << "Case #" << f << ": " << rec(0, q + 1) << endl;
    }
}

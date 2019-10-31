#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

int n;
int c[60];
int dp[60][60];

int rec(int i, int j)
{
    // cout << i << " " << j << << dp[i][j] << endl;
    if(j - i <= 1) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mi = INF;
    for(int k = i + 1; k < j; k++)
    {
        mi = min(mi, rec(i, k) + rec(k, j));
    }
    dp[i][j] = (mi + c[j] - c[i]);
    return dp[i][j];
}

int main(void)
{
    int l;
    cin >> l;

    while(l != 0)
    {
        cin >> n;

        for(int i = 0; i <= n + 1; i++)
        {
            for(int j = 0; j <= n + 1; j++)
            {
                dp[i][j] = -1;
            }
        }

        c[0] = 0;
        c[n + 1] = l;

        for(int i = 1; i <= n; i++) cin >> c[i];
        // for(int i = 0; i <= n + 1; i++) cout << c[i] << " ";
        // cout << endl;

        cout << "The minimum cutting is " <<  rec(0, n + 1) << "." << endl;
        cin >> l;
    }
    return 0;
}

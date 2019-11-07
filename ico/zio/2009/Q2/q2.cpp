/*
5
-2 1 -3 4 -4
12 -16 10 -12 6
-16 13 -14 7 -4
7 -4 16 -15 10
-7 16 -9 13 -16
*/

/*
6
-6 5 -4 7 -5 11
7 -6 7 -10 10 -4
-6 10 -5 4 -6 7
8  -7 10 -5 5 -10
-9 11 -7 11 -7 4
8 -10 5 -9 5 -6
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int a[n + 1][n + 1] = {};
    int dp[n + 1][n + 1] = {};

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    int ma = INT_MIN;

    for(int i = n; i >= 1; i--)
    {
        for(int j = n; j >= 1; j--)
        {
            dp[i][j] = a[i][j];

            if(i == n && j != n) dp[i][j] += max(0, dp[i][j + 1]);

            if(j == n && i != n) dp[i][j] += max(0, dp[i + 1][j]);

            if(i != n && j != n) dp[i][j] += max(dp[i + 1][j], dp[j + 1][i]);

            ma = max(ma, dp[i][j]);
        }
    }

    // for(int i = 0; i <= n; i++) { for(int j = 0; j <= n; j++) { cout << dp[i][j] << " "; } cout << endl; }
    cout << ma << endl;
}

#include <bits/stdc++.h>

using namespace std;

int dp[600][600];

int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;

        dp[1][1] = 1;

        for(int i = 1; i <= a; i++)
        {
            for(int j = 1; j <= b; j++)
            {
                if(i == j) dp[i][j] = 1;
                else
                {
                    dp[i][j] = INT_MAX;
                    for(int k = 1; k < i; k++)
                    {
                        dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j]);
                    }
                    for(int k = 1; k < j; k++)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k]);
                    }
                    dp[j][i] = dp[i][j];
                }
            }
        }

        // for(int i = 0; i <= a; i++) { for(int j = 0; j <= b; j++) cout << dp[i][j]; cout << endl; }
        cout << dp[a][b] << endl;
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;

    int a[n + 1] = {};
    for(int i = 1; i <= n; i++) cin >> a[i];

    int isP[n + 1][n + 1] = {};

    for(int j = 1; j <= n; j++)
    {
        for(int i = 1; i <= n - j + 1; i++)
        {
            if(j <= 2)
            {
                if(a[i] == a[i + j - 1]) isP[i][i + j - 1] = true;
                continue;
            }
            if(a[i] == a[i + j - 1] && isP[i + 1][i + j - 2]) isP[i][i + j - 1] = true;
            else isP[i][i + j - 1] = false;
        }
    }

    int dp[n + 1][n + 1] = {};

    for(int j = 1; j <= n; j++)
    {
        for(int i = 1; i <= n - j + 1; i++)
        {
            if(isP[i][i + j - 1]) dp[i][i + j - 1] = 1;
            else
            {
                int mi = 1 + dp[i + 1][i + j - 1];
                if(a[i] == a[i + 1]) mi = min(mi, 1 + dp[i + 2][i + j - 1]);
                for(int k = i + 2; k <= i + j - 1; k++)
                {
                    if(a[i] == a[k]) mi = min(mi, dp[i + 1][k - 1] + dp[k + 1][i + j - 1]);
                }

                dp[i][i + j - 1] = mi;
            }
        }
    }
    cout << dp[1][n] << endl;
}

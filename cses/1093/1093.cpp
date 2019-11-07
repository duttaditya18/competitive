#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007

int main(void)
{
    int n;
    cin >> n;

    if((n % 4) == 1 || (n % 4) == 2)
    {
        cout << 0 << endl;
        return 0;
    }

    int ma = n * (n + 1) / 2;

    int dp[n + 1][ma + 1] = {};

    dp[0][0] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= ma; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if(j >= i) (dp[i][j] += dp[i - 1][j - i]) %= MOD;
        }
    }

    // for(int i = 0; i <= ma; i++) cout << dp[n][i] << " "; cout << endl;

    cout << dp[n][ma / 2] << endl;
}

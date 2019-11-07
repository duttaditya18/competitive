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

    int dp[ma + 1] = {};

    dp[0] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = ma; j >= 0; j--)
        {
            if(j < i) break;
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }

    // for(int i = 0; i <= ma; i++) cout << dp[i] << " "; cout << endl;

    cout << dp[ma / 2] / 2 << endl;
}

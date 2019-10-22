#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main(void)
{
    int n, k, d;
    cin >> n >> k >> d;

    int dp[n + 1] = {};
    int dpw[n + 1] = {};
    dp[0] = 1;
    dpw[0] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(i - j >= 0)
            {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
                if(j < d) dpw[i] = (dpw[i] + dpw[i - j]) % MOD;
            }
        }
    }



    //for(int i = 0; i <= n; i++) cout << dpw[i] << " ";
    //cout << "\n";

    int ans = ((dp[n] - dpw[n]) + MOD) % MOD;
    cout << ans << "\n";
}

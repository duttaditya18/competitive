#include <bits/stdc++.h>

using namespace std;

const int mod = 10000;
const int maxn = 1000005;

int dp[maxn + 10];
int gp[maxn + 10];

int main(void)
{
    int n; cin >> n;

    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + gp[i - 1];
        if(i >= 2)
        {
            dp[i] = (dp[i] + dp[i - 2]) % mod;
            gp[i] = (2 * dp[i - 2] + gp[i - 1]) % mod;
        }
        // if(dp[i] == 0) cout << i << endl;
    }
    cout << dp[n] << "\n";
}

#include <bits/stdc++.h>

using namespace std;
#define MAXN 100010
#define MOD 1000000007

int main(void)
{
    int t, k; cin >> t >> k;

    int dp[100010] = {}, pr[100010] = {};
    dp[0] = 1;

    for(int i = 1; i <= 100000; i++)
    {
        dp[i] = (dp[i - 1]) % MOD;
        if(i >= k) dp[i] = (dp[i] + dp[i - k]) % MOD;
        pr[i] = (pr[i] + pr[i - 1] + dp[i]) % MOD;
    }
    int a, b;
    while(t--)
    {
        cin >> a >> b;
        cout << ((pr[b] - pr[a - 1]) % MOD + MOD) % MOD << endl;
    }
    return 0;
}

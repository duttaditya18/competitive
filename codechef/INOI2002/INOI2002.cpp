#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000000;
const int mod = 1e9 + 7;

long long dp2[maxn + 10];
long long dp[maxn + 10];
long long gp[maxn + 10];
long long hp[maxn + 10];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    dp2[0] = 1;
    dp2[2] = 1;

    for(int i = 3; i <= maxn; i++) dp2[i] = (dp2[i - 2] + dp2[i - 3]) % mod;

    dp[0] = 1;
    for(int i = 1; i <= maxn; i++)
    {
        dp[i] = dp[i - 1];
        gp[i] = hp[i - 1];

        if(i >= 2)
        {
            dp[i] = (dp[i] + gp[i - 2]) % mod;
        }
        if(i >= 3)
        {
            dp[i] = (dp[i] + dp[i - 3]) % mod;
            gp[i] = (gp[i] + gp[i - 3]) % mod;
            hp[i] = (hp[i] + (2*dp[i - 3]) + hp[i - 3]) % mod;
        }
    }

    int t; cin >> t;
    int k, n;
    while(t--)
    {
        cin >> k >> n;
        if(k == 1) cout << ((n % 3) ? 0 : 1);
        else if(k == 2) cout << dp2[n];
        else if(k == 3) cout << dp[n];
        cout << "\n";
    }
}

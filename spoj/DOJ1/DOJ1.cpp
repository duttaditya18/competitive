#include <bits/stdc++.h>

using namespace std;

int t, n, m, jc, ic, mod;

int main(void)
{
    cin >> t;

    while(t--)
    {
        cin >> n >> m >> jc >> ic >> mod;
        if(!(n % 2) || !(m % 2)) cout << 0;
        else if (n == 1) cout << 1;
        else if(n == 3)
        {
            if(!(jc % 2)) cout << 0;
            else
            {
                int dp[m + 1] = {};
                int gp[m + 1] = {};
                dp[0] = 1;

                for(int i = 1; i <= m; i++)
                {
                    if(i == ic)
                    {
                        gp[i] = dp[i - 1];
                        dp[i] = gp[i];
                    }
                    else
                    {
                        if(i >= 2) gp[i] = (2*dp[i - 2] + gp[i - 2]) % mod;
                        dp[i] = gp[i];
                        if(i >= 2) dp[i] = (dp[i] + dp[i - 2]) % mod;
                    }
                    cout << i << " : " << dp[i] << "\n";
                }
                cout << dp[m];
            }
        }
        cout << "\n";
    }
}

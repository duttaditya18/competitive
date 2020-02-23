#include <bits/stdc++.h>

using namespace std;

const int maxn = 21;
int t, n;

int dp[maxn + 5];
int gp[maxn + 5];
int hp[maxn + 5];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    dp[0] = 1;

    for(int i = 1; i <= maxn; i++)
    {
        gp[i] = gp[i - 1];
        if(i >= 2) gp[i] += 2*dp[i - 2];
        dp[i] = dp[i - 1] + gp[i] + hp[i - 1];
        if(i >= 2) dp[i] += dp[i - 2];
        hp[i] = dp[i - 1];
        if(i >= 2) hp[i] += hp[i - 2];
        /*if(dp[i] >= INT_MAX)
        {
            cout << "hehe: " << i << endl;
            return 0;
        }*/
    }

    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cin >> n;
        cout << i << " " << dp[n] << "\n";
    }
    return 0;
}

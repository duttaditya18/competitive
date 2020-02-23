#include <bits/stdc++.h>

using namespace std;

const int maxn = 35;

int dp[maxn + 10];
int gp[maxn + 10];

int main(void)
{
    dp[0] = 1;
    dp[1] = 0;
    for(int i = 1; i <= maxn; i++)
    {
        dp[i] = gp[i - 1];
        gp[i] = (2*dp[i - 1]);
        if(i >= 2)
        {
            dp[i] += dp[i - 2];
            gp[i] += gp[i - 2];
        }
    }

    int n; cin >> n;
    while(n != -1)
    {
        cout << dp[n] << "\n";
        cin >> n;
    }
}

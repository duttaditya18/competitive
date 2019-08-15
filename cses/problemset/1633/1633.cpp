// WTF am I doing. TLE THE FUCK OUT

#include <bits/stdc++.h>

using namespace std;

int dp[1000005] = {};
bool ready[1000005] = {};

int solve(int x)
{
    if(ready[x]) return dp[x];
    int ans = 0;
    for(int i = 1; i <= 6; i++)
    {
        if(ready[x-i])
        {
            ans += dp[x-i];
        }
        else
        {
            solve(x - i);
            ans += dp[x - i];
        }
    }
    dp[x] = ans;
    ready[x] = true;
    return ans;
}

int main(void)
{
    int n;
    cin >> n;
    dp[0] = 1, ready[0] = true;
    dp[1] = 1, ready[1] = true;
    dp[2] = 2, ready[2] = true;
    dp[3] = 4, ready[3] = true;
    dp[4] = 8, ready[4] = true;
    dp[5] = 16, ready[5] = true;
    dp[6] = 32, ready[6] = true;

    cout << solve(n);
}

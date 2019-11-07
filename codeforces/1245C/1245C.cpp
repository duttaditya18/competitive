#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007

int main(void)
{
    string s;
    cin >> s;
    int n = s.size();

    int dp[n + 1] = {};
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(s[i - 1] == 'w' || s[i - 1] == 'm')
        {
            cout << 0 << endl;
            return 0;
        }
        if(i == 1) dp[i] = 1;
        else
        {
            if(s[i - 1] == s[i - 2] && (s[i - 1] == 'u' || s[i - 1] == 'n')) dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
            else dp[i] = dp[i - 1];
        }
    }
    cout << dp[n] << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s;
    cin >> s;
    while(s != "0")
    {
        bool f  = true;
        int n = s.size();
        long long dp[n + 1] = {};
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 1; i < n; i++)
        {
            if(s[i] != '0') dp[i + 1] = dp[i];
            int x = (10 * (s[i - 1] - '0')) + (s[i] - '0');
            if(x >= 10 && x <= 26) dp[i + 1] += dp[i - 1];
        }
        cout << dp[n] << endl;
        cin >> s;
    }
    return 0;
}

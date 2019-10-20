// TLE

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s;
    cin >> s;

    int n = s.size();

    int f[n + 1] = {};
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        f[i] = (f[i - 1] ^ (1 << (s[i - 1] - 'a')));
    }

    // for(int i = 0; i < n + 1; i++) cout << f[i] << " ";
    // cout << "\n";

    for(int i = 1; i <= n; i++)
    {
        int mi = INT_MAX;
        for(int j = i - 1; j >= 0; j--)
        {
            if(__builtin_popcount(f[i]^f[j]) == 1 || __builtin_popcount(f[i]^f[j]) == 0)
            {
                // cout << i << "\n";
                mi = min(mi, dp[j] + 1);
            }
        }
        dp[i] = mi;
    }

    cout << dp[n] << "\n";

}

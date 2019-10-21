#include <bits/stdc++.h>

using namespace std;

int dp[1 << 26];
#define INF (INT_MAX/2)

int main(void)
{
    string s;
    cin >> s;
    int n = s.length();

    for(int i = 0; i < (1 << 26); i++) dp[i] = INF;

    int b = 0;
    dp[0] = 0;
    for(int i = 0; i < n; i++)
    {
        b ^= (1 << (s[i] - 'a'));
        int t = dp[b];

        // Check if it is possible to make the current substring starting from i to a palindrome and getting the minimum
        for(int j = 0; j < 26; j++)
        {
            t = min(t, dp[b ^ (1 << j)]);
        }
        dp[b] = min(dp[b], t + 1);
        // cout << dp[b] << "\n";
    }

    // If it is possible to make the whole string into a palindrome, dp[b] is zero
    cout << (dp[b] == 0 ? 1 : dp[b]) << "\n";
    return 0;
}

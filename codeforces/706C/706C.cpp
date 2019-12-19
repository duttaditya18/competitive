#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;

    string s[n], r[n];
    long long c[n];

    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        r[i] = s[i];
        reverse(r[i].begin(), r[i].end());
    }

    // 0 - no reverse, 1 - reverse
    long long dp[n][2] = {};

    dp[0][0] = 0ll;
    dp[0][1] = c[0];

    for(int i = 1; i < n; i++)
    {
        if(s[i] >= s[i - 1] && dp[i - 1][0] != LLONG_MAX) dp[i][0] = dp[i - 1][0];
        else dp[i][0] = LLONG_MAX;

        if(s[i] >= r[i - 1]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);

        if(r[i] >= s[i - 1] && dp[i - 1][0] != LLONG_MAX) dp[i][1] = dp[i - 1][0];
        else dp[i][1] = LLONG_MAX;

        if(r[i] >= r[i - 1]) dp[i][1] = min(dp[i][1], dp[i - 1][1]);
        if(dp[i][1] != LLONG_MAX) dp[i][1] += c[i];
    }

    if(dp[n - 1][0] != LLONG_MAX || dp[n - 1][1] != LLONG_MAX) cout << min(dp[n - 1][0], dp[n - 1][1]);
    else cout << -1;
    cout << endl;

    //for(int i = 0; i < n; i++) cout << dp[i][0] << " "; cout << endl;
    //for(int i = 0; i < n; i++) cout << dp[i][1] << " ";


    return 0;
}

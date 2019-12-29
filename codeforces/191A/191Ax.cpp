#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;
    string s;
    // start chacter, end character, size
    tuple<int, int, int> a[n + 1];

    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        a[i] = make_tuple(int(s.front() - 'a'), int(s.back() - 'a'), s.size());
    }

    // position, starting, ending
    int dp[26][26] = {};

    int st, en, si;

    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            dp[i][j] = INT_MIN;

    for(int i = 1; i <= n; i++)
    {
        st = get<0>(a[i]);
        en = get<1>(a[i]);
        si = get<2>(a[i]);

        for(int j = 0; j < 26; j++)
        {
            if(dp[j][st] != INT_MIN)
            {
                dp[j][en] = max(dp[j][en], dp[j][st] + si);
                // cout << i << " " << char(j + 'a') << " " << char(st + 'a') << " " << char(en + 'a') << " " << dp[j][en] << endl;
            }
        }
        dp[st][en] = max(dp[st][en], si);
    }


    int ans = 0;

    for(int i = 0; i < 26; i++) ans = max(ans, dp[i][i]);

    cout << ans << endl;
}

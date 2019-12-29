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
    int dp[n + 1][26][26] = {};

    int st, en, si;

    for(int k = 0; k <= n; k++)
        for(int i = 0; i < 26; i++)
            for(int j = 0; j < 26; j++)
                dp[k][i][j] = INT_MIN;

    for(int i = 1; i <= n; i++)
    {
        st = get<0>(a[i]);
        en = get<1>(a[i]);
        si = get<2>(a[i]);

        for(int j = 0; j < 26; j++)
        {
            for(int k = 0; k < 26; k++)
            {
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                if(j == st && k == en)
                {
                    dp[i][j][k] = max(dp[i][j][k], si);
                    // cout << "ne: " << i << " " << char(j + 'a') << " " << char(k + 'a') << " " << dp[i][j][k] << endl;
                }
                if(k == st && dp[i - 1][j][k] != INT_MIN)
                {
                    dp[i][j][en] = max(dp[i][j][en], dp[i - 1][j][k] + si);
                    // cout << "pr: " << i << " " << char(j + 'a') << " " << char(k + 'a') << " " << char(en + 'a') << " " << dp[i][j][en] << endl;
                }
            }
        }
    }


    int ans = 0;

    for(int i = 0; i < 26; i++) ans = max(ans, dp[n][i][i]);

    cout << ans << endl;
}

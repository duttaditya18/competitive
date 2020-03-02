#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;
    string s; cin >> s;

    int dp[n][n] = {};

    pair<int, int> p(0, 0);
    int mx = 1;

    for(int i = 0; i < n; i++) dp[i][i] = 1;

    for(int k = 1; k < n; k++)
    {
        for(int i = 0; i < n - k; i++)
        {
            if(k == 1)
            {
                if(s[i] == s[i + 1])
                    dp[i][i + 1] = 1;
            }
            else
            {
                if(s[i] == s[i + k] && dp[i + 1][i + k - 1])
                    dp[i][i + k] = 1;
            }
            if(dp[i][i + k])
            {
                if(k + 1 > mx)
                {
                    p = {i, i + k};
                    mx = k + 1;
                }
            }
        }
    }

    // for(int i = 0; i < n; i++) { for(int j = 0; j < n; j++) cout << dp[i][j]; cout << "\n"; }
    cout << mx << "\n";
    for(int i = p.first; i <= p.second; i++) cout << s[i]; cout << "\n";
    return 0;
}

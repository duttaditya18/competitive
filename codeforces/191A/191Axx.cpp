#include <bits/stdc++.h>

using namespace std;

int n, st, en, si, ans;
int dp[26][26] = {};
string s;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    while(n--)
    {
        cin >> s;
        st = s[0] - 'a';
        si = s.size();
        en = s[si - 1] - 'a';
        for(int i = 0; i < 26; i++)
            if(dp[i][st] || i == st)
            {
                dp[i][en] = max(dp[i][en], dp[i][st] + si);
                ans = max(ans, dp[i][i]);
            }
    }

    cout << ans << endl;
}

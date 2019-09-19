#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {

        int ss, ts;
        cin >> ss >> ts;

        string s, t;
        cin >> s >> t;

        int dp[ss + 1][ts + 1] = {};

        for(int i = 1; i <= ss; i++)
        {
            for(int j = 1; j <= ts; j++)
            {
                if(s[i - 1] == t[j - 1])
                    dp[i][j] += 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        /*for(int i = 0; i <= ss; i++)
        {
            for(int j = 0; j <= ts; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/
        cout << dp[ss][ts] << endl;
    }
    return 0;
}

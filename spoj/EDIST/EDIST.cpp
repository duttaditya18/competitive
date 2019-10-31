#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        string s1, s2;
        cin >> s1;
        cin >> s2;

        int n1 = s1.size(), n2 = s2.size();

        int dp[n1 + 1][n2 + 1] = {};

        // for(int i = 0; i <= n1; i++) dp[i][0] = i;
        // for(int i = 0; i <= n2; i++) dp[0][i] = i;

        for(int i = 0; i <= n1; i++)
        {
            for(int j = 0; j <= n2; j++)
            {
                if(i == 0) dp[i][j] = j;
                else if(j == 0) dp[i][j] = i;
                else
                {
                    if(s1[i - 1] == s2[j - 1])
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else
                    {
                        dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                    }
                }
            }
        }

        cout << dp[n1][n2] << endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s, t;
    cin >> s >> t;

    int ss = s.size(), ts = t.size();

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

    string x = "";

    int is = ss;
    int js = ts;

    while(js != 0 && ts != 0)
    {
        if(dp[is][js] == dp[is][js - 1])
            js--;
        else if(dp[is][js] == dp[is - 1][js])
            is--;
        else if(dp[is][js] > dp[is - 1][js] && dp[is][js] > dp[is][js - 1])
        {
            x += (s[is - 1]);
            is--;
            js--;
        }
    }

    reverse(x.begin(), x.end());

    cout << x << endl;

    /*for(int i = 0; i <= ss; i++)
    {
        for(int j = 0; j <= ts; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[ss][ts];*/

    return 0;
}

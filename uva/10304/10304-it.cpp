#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    // ifstream cin("in.in");
    // ofstream cout("out.out");
    int n;
    while(cin >> n)
    {
        int dp[n + 2][n + 2] = {};
        int a[n + 2] = {};
        int prf[n + 2] = {};
        for(int i = 0; i <= n + 1; i++)
        {
            for(int j = 0; j <= n + 1; j++)
            {
                dp[i][j] = -1;
            }
        }
        a[0] = 0;
        prf[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            prf[i] = a[i];
            prf[i] += prf[i - 1];
        }
        a[n + 1] = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= n - i; j++)
            {
                if(i == 0)
                {
                    dp[j][j] = 0;
                    continue;
                }
                int mi = INT_MAX;
                int en = j + i;
                int st = j;
                for(int k = st; k <= en; k++)
                {
                    if(k == st)
                    {
                        mi = min(mi, dp[k + 1][en] - a[k]);
                    }
                    else if(k == en)
                    {
                        mi = min(mi, dp[st][k - 1] - a[k]);
                    }
                    else
                    {
                        mi = min(mi, dp[st][k - 1] + dp[k + 1][en] - a[k]);
                    }
                }
                dp[st][en] = mi + prf[en] - prf[st - 1];
            }
        }
        cout << dp[1][n] << endl;
    }
    return 0;
}

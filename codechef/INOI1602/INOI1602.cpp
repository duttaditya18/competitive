#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m; cin >> n >> m;

    int v[n + 1] = {}, b[n + 1] = {};

    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    int dp[n + 1][n + 1] = {};

    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j + i - 1 <= n; j++)
        {
            int st = j;
            int la = j + i - 1;

            if(b[la] - b[st] == m)
            {
                dp[st][la] = max(dp[st][la], v[st] + v[la] + dp[st + 1][la - 1]);
            }

            for(int k = st + 1; k <= la; k++)
            {
                dp[st][la] = max(dp[st][la], dp[st][k - 1] + dp[k][la]);
            }
        }
    }

    cout << dp[1][n] << endl;
}

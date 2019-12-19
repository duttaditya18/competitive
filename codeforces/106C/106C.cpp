#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m, iw, ic;
    cin >> n >> m >> iw >> ic;

    int q[m + 1] = {}, w[m + 1], c[m + 1] = {};

    int a, b, x, d;

    for(int i = 1; i <= m; i++)
    {
        cin >> a >> b >> x >> d;

        q[i] = a / b;
        w[i] = x;
        c[i] = d;
    }

    int dp[m + 1][n + 1] = {};

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int ma = 0;
            for(int k = 1; k <= q[i]; k++)
            {
                if(j >= (w[i]*k)) ma = max({ma, dp[i - 1][j - (w[i]*k)] + (k*c[i])});
            }
            dp[i][j] = max(ma, dp[i - 1][j]);
        }
    }

    int ans = 0;

    for(int i = 0; (i*iw) <= n; i++)
    {
        ans = max(ans, dp[m][n - (i*iw)]  + (i*ic));
    }

    cout << ans << endl;

    //for(int i = 0; i <= m; i++) { for(int j = 0; j <= n; j++) { cout << dp[i][j] << " "; } cout << endl; }

    /*
    See constraints (long long)
    See if declarations are done properly
    Think hard about corner cases (some special value)
    See if loop goes through the right values
    */
}

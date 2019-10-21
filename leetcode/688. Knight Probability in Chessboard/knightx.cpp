#include <bits/stdc++.h>

using namespace std;


double knightProbability(int N, int K, int r, int c)
{
    int dr[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dc[] = {1, -1, 1, -1, 2, -2, 2, -2};
    double dp[N][N] = {};

    dp[r][c] = 1;

    for(int i = 0; i < K; i++)
    {
        double dp0[N][N] = {};
        for(int rn = 0; rn < N; rn++)
        {
            for(int cn = 0; cn < N; cn++)
            {
                for(int j = 0; j < 8; j++)
                {
                    int rf = rn + dr[j];
                    int cf = cn + dc[j];
                    if(0 <= rf and 0 <= cf and rf < N and cf < N)
                    {
                        dp0[rf][cf] += (dp[rn][cn] / 8.0);
                        // cout << dp0[rf][cf] << endl;
                    }
                }
            }
        }
        memcpy(dp, dp0, sizeof(dp0));
    }

    double ans = 0.0;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            //cout << dp[i][j] << " ";
            ans += dp[i][j];
        }
        //cout << "\n";
    }
    return ans;
}

int main(void)
{
    int n, k, r, c;
    // cin >> n >> k >> r >> c;

    n = 3, k = 2, r = 0, c = 0;

    cout << knightProbability(n, k, r, c) << "\n";
}

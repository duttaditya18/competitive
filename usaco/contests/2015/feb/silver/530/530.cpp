#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int a[102][102] = {};
    int dp[102][102] = {};

    ifstream cin("hopscotch.in");
    ofstream cout("hopscotch.out");
    int r, c, k;
    cin >> r >> c >> k;


    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            cin >> a[i][j];
        }
    }

    dp[r][c] = 1;

    for(int i = r; i >= 1; i--)
    {
        for(int j = c; j >= 1; j--)
        {
            for(int ix = i + 1; ix <= r; ix++)
            {
                for(int jx = j + 1; jx <= c; jx++)
                {
                    if(a[i][j] != a[ix][jx])
                    {
                        dp[i][j] = (dp[i][j] + dp[ix][jx]) % 1000000007;
                    }
                }
            }
        }
    }

    cout << dp[1][1] << endl;
}

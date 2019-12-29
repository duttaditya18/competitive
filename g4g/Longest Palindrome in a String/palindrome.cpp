#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t; cin >> t;
    while(t--)
    {
        string a; cin >> a;
        int n = a.size();

        int dp[n + 1][n + 1] = {};

        int ans = 0, ansI, ansJ;

        for(int j = 1; j <= n; j++)
        {
            for(int i = 0; i <= n - j; i++)
            {
                if(j <= 2)
                {
                    if(a[i] == a[i + j - 1]) dp[i][i + j - 1] = true;
                }
                else if(a[i] == a[i + j - 1]) dp[i][i + j - 1] = dp[i + 1][i + j - 2];

                if(dp[i][i + j - 1] && j > ans)
                {
                    ans = j;
                    ansI = i;
                    ansJ = i + j - 1;

                }
            }
        }
        for(int i = ansI; i <= ansJ; i++) cout << a[i]; cout << endl;
    }
}

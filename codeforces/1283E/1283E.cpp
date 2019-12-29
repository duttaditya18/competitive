#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;
    int a[n + 1] = {};

    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a, a + n + 1);

    // for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;

    // -1, 0, +1
    int dp[n + 1][3] = {};
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;

    for(int i = 2; i <= n; i++)
    {
        dp[i][0] = INT_MAX;
        dp[i][1] = INT_MAX;
        dp[i][2] = INT_MAX;
        for(int j = -1; j <= 1; j++)
        {
            for(int k = -1; k <= 1; k++)
            {
                if(a[i] + j == a[i - 1] + k) dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][k + 1]);
                else dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][k + 1] + 1);
            }
        }
    }

    int lb = a[1] - 1;
    int c = 1;
    for(int i = 2; i <= n; i++)
    {
        if(a[i] < lb)
        {
            continue;
        }
        else if(a[i] == lb)
        {
            lb = a[i] + 1;
            c++;
        }
        else if(a[i] > lb)
        {
            if(a[i] - 1 > lb) lb = a[i] - 1;
            else lb = a[i];
            c++;
        }
    }


    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << " " << c << endl;
    return 0;
}

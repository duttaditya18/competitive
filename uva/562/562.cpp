#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        int a[n + 1] = {}, sum = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        int x = sum / 2;

        int dp[x + 1] = {};

        for(int i = 1; i <= n; i++)
        {
            for(int j = x; j >= 0; j--)
            {
                if(j < a[i]) break;
                dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
            }
        }
        cout << sum - (2 * dp[x]) << endl;
    }
}

#include <bits/stdc++.h>

using namespace std;

int dp[200010];

int main(void)
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    int ma = 0;

    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(a[i] > a[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            ma = max(ma, dp[i]);
        }
    }

    //for(int i = 0; i < n; i++) cout << dp[i] << " ";
    cout << ma << endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;

    int a[n];
    long long sum = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += 1ll*a[i];
    }

    if(n < 3)
    {
        cout << sum << endl;
        return 0;
    }

    int dp[n] = {};
    dp[0] = a[0]; dp[1] = a[1]; dp[2] = a[2];

    for(int i = 3; i < n; i++) dp[i] = min({dp[i - 1], dp[i - 2], dp[i - 3]}) + a[i];

    cout << sum - min({dp[n - 1], dp[n - 2], dp[n - 3]}) << endl;
    return 0;
}

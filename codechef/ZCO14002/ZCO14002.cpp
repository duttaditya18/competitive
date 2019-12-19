#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;

    if(n < 3)
    {
        cout << 0 << endl;
        return 0;
    }

    long long dp[n + 1] = {}, x;
    cin >> dp[1] >> dp[2] >> dp[3];

    for(int i = 4; i <= n; i++)
    {
        cin >> x;
        dp[i] = min({dp[i - 1], dp[i - 2], dp[i - 3]}) + x;
    }

    cout << min({dp[n], dp[n - 1], dp[n - 2]}) << endl;
    return 0;
}

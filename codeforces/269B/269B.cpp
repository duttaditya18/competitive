#include <bits/stdc++.h>

using namespace std;


int main(void)
{
    vector<pair<float, int>> a;
    int n, m, x;
    float y;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        a.push_back(make_pair(y, x));
    }

    sort(a.begin(), a.end());

    // for(int i = 0; i < n; i++) { cout << a[i].first << " " << a[i].second << endl; }

    int dp[n + 1] = {}, ma = 0;
    for(int i = 1; i <= n; i++) dp[i] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(a[i - 1].second <= a[j - 1].second) dp[j] = max(dp[j], dp[i] + 1);
            // cout << i << " " << j << " " << a[i - 1].second << " " << a[j - 1].second << " " << dp[j] << endl;
        }
        ma = max(ma, dp[i]);
    }

    // for(int i = 0; i <= n; i++) cout << dp[i] << " "; cout << endl;

    cout << n - ma << endl;
}

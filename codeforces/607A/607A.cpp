#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;

    int x, y;

    // position, power
    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end());

    // for(int i = 0; i < n; i++) cout << v[i].first << " " << v[i].second << endl;

    int dp[n + 1];
    dp[0] = 0;

    int ans = n - 1;

    for(int i = 1; i < n; i++)
    {
        int del = i - (lower_bound(v.begin(), v.end(), make_pair((v[i].first - v[i].second), INT_MIN)) - v.begin());
        dp[i] = del;
        if(i - del - 1 >= 0) dp[i] += dp[i - del - 1];
        ans = min(ans, dp[i] + n - 1 - i);
    }
    cout << ans << endl;
}

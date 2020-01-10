#include <bits/stdc++.h>

using namespace std;

int maximumSum(vector<int> &a)
{
    // 0 = No Deletions, 1 = One Deletion
    int n = a.size();
    int dp[2] = {};
    dp[0] = a[0];
    dp[1] = 0;

    int ans = dp[0];

    for(int i = 1; i < n; i++)
    {
        dp[1] = max(dp[0], dp[1] + a[i]);
        dp[0] = max(dp[0] + a[i], a[i]);
        ans = max({ans, dp[0], dp[1]});
    }

    return ans;
}

int main(void)
{
    vector<int> v{-1,-1,-1,-1};
    cout << maximumSum(v);
}

#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k)
{
    int n = nums.size();

    int p[n + 1] = {};

    unordered_multiset<int> m;

    int ans = 0;

    m.insert(0);

    for(int i = 1; i <= n; i++)
    {
        p[i] = nums[i - 1];
        p[i] += p[i - 1];

        ans += m.count(p[i] - k);
        m.insert(p[i])++;
    }

    return ans;
}
int main(void)
{
    vector<int> nums{1, -1, 2, -2};
    cout << subarraySum(nums, 0);
}

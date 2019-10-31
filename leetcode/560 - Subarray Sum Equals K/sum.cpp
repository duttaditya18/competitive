#include <bits/stdc++.h>

using namespace std;
int subarraySum(vector<int>& nums, int k)
{
    int n = nums.size();

    int p[n + 1] = {};

    for(int i = 1; i <= n; i++)
    {
        p[i] = nums[i - 1];
        p[i] += p[i - 1];
    }

    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            if(p[j] - p[i - 1] == k) ans++;
        }
    }

    return ans;
}
int main(void)
{
    vector<int> nums{1, 1, 1};
    cout << subarraySum(nums, 2);
}

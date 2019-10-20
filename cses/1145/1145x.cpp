// wow

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int x[n];
    vector<int> nums;
    vector<int>::iterator itr;

    for(int i = 0; i < n; i++) cin >> x[i];

    for(int i = 0; i < n; i++)
    {
        if(i == 0) nums.push_back(x[i]);
        else
        {
            int si = nums.size() - 1;
            if(nums[si] < x[i]) nums.push_back(x[i]);
            else if(nums[si] > x[i])
            {
                itr = lower_bound(nums.begin(), nums.end(), x[i]);
                *itr = x[i];
            }
        }
    }


    //for(int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
    //cout << endl;

    cout << nums.size() << endl;
    return 0;
}

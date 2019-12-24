#include<bits/stdc++.h>
using namespace std;

class ZigZag
{
    public:
    int longestZigZag(vector<int> s)
    {
    	vector<int> a = s;
    	int n = s.size();
    	// 0 - curr is lower, 1 - curr is greater
    	int dp[n + 1][2];

    	for(int i = 0; i < n; i++)
    	{
    		dp[i][0] = 1;
    		dp[i][1] = 1;
    	}
    	int ans = 1;

    	for(int i = 1; i < n; i++)
    	{
    		for(int j = i - 1; j >= 0; j--)
    		{
    			if(a[j] > a[i]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
    			if(a[j] < a[i]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
    		}
    		ans = max({dp[i][0], dp[i][1], ans});
    	}
    	return ans;
	}
};

int main(void)
{
    ZigZag x;
    cout << x.longestZigZag({1,2,3});
}

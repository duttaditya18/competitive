#include<bits/stdc++.h>
using namespace std;

int dp[50];
int dx[50];

class BadNeighbors
{
    public:
    int maxDonations(vector<int> a)
    {
        int n = a.size();
        dp[0] = a[0];
        dp[1]  = a[1];

        int ans = max(dp[0], dp[1]);

        for(int i = 2; i < n - 1; i++)
        {
            dp[i] = max(dp[i], dp[i - 2] + a[i]);
            if(i >= 3) dp[i] = max(dp[i], dp[i - 3] + a[i]);
            ans = max(ans, dp[i]);
        }

        dx[0] = 0;
        dx[1] = a[1];

        for(int i = 2; i < n; i++)
        {
            dx[i] = max(dx[i], dx[i - 2] + a[i]);
            if(i >= 3) dx[i] = max(dx[i], dx[i - 3] + a[i]);
            ans = max(ans, dx[i]);
        }

        return ans;
	}
};

int main(void)
{
    BadNeighbors x;
    cout << x.maxDonations({ 10, 3, 2, 5, 7, 8 });
}

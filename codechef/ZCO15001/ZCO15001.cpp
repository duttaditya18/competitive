#include <bits/stdc++.h>

using namespace std;

vector<int> a;

bool isPal(int l, int r)
{
    int s = (r + l) / 2;

    for(int i = l; i <= s; i++)
    {
        if(a[i] != a[r - i + l]) return 0;
    }
    return 1;
}

int main(void)
{
    int n; cin >> n;

    int x;
    a.push_back(0);
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        a.push_back(x);
    }

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j >= 1; j--)
        {
            if(isPal(j, i))
            {
                // cout << j << " " << i << endl;
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }

    cout << dp[n] << endl;
}

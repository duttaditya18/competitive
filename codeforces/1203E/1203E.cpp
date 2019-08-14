#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int dp[150003] = {}, a[n], max = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());

    for(int i = 0; i < n; i++)
    {
         if(dp[a[i] + 1] == 0)
        {
            dp[a[i] + 1] = 1;
            max ++;
        }
        else if(dp[a[i]] == 0)
        {
            dp[a[i]] = 1;
            max++;
        }
        else if(dp[a[i] - 1] == 0 and a[i] > 1)
        {
            dp[a[i] - 1] = 1;
            max++;
        }
    }

    cout << max;

    return 0;
}

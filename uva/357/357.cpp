#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long dp[30001] = {};
    dp[0] = 1;

    int cc = 5;
    int c[cc] = {1, 5, 10, 25, 50};

    // for(int i = 0; i < 5; i++) cout << c[i] << endl;

    for(int i = 0; i < cc; i++)
    {
        for(int j = c[i]; j <= 30000; j++)
        {
            dp[j] += dp[j - c[i]];
        }
    }

    int x;
    while(cin >> x)
    {
        if(x <= 4) cout << "There is only 1 way to produce " << x << " cents change.";
        else cout << "There are " << dp[x] << " ways to produce " << x << " cents change.";
        cout << "\n";
    }
    return 0;
}

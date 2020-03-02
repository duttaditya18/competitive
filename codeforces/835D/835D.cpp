#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s; cin >> s;
    int n = s.size();

    int a[n + 1] = {};
    a[1] = n;
    int dp[n][n] = {};

    for(int i = 0; i < n; i++) dp[i][i] = 1;

    for(int k = 1; k < n; k++)
    {
        for(int i = 0; i < n - k; i++)
        {
            if(k == 1)
            {
                if(s[i] == s[i + 1])
                {
                    // cout << "x " << i << " " << i + k << " " << a[i] << " " << a[i + k] << "\n";
                    dp[i][i + 1] = 2;
                    a[dp[i][i + 1]]++;
                }
            }
            else
            {
                // cout << i << " " << i + k << " " <<  dp[i + 1][i + k - 1] << "\n";
                if(s[i] == s[i + k] && dp[i + 1][i + k - 1])
                {
                    // cout << i << "," << i + k << " : " << dp[i + 1][i + k - 1] << " :: " << i << "," << i + ((k)/2) << " : " << dp[i][i + ((k + 1)/2)] << "\n";
                    dp[i][i + k] = 1 + dp[i][i + (((k + 1)/2) - 1)];
                    a[dp[i][i + k]]++;
                }
            }
        }
    }
    for(int i = n - 1; i >= 1; i--) a[i] += a[i + 1];
    for(int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
    return 0;
}

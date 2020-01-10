#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s, int st, int en)
{
    while(en > st)
    {
        if(s[st] != s[en]) return false;
        st++;
        en--;
    }
    return true;
}

int minCut(string s)
{
    int INF = (INT_MAX/2);
    int n = s.size();

    int dp[n + 1];
    for(int i = 0; i <= n; i++) dp[i] = INF;
    dp[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        int t = INT_MAX;
        for(int j = i - 1; j >= 0; j--)
        {
            if(isPalindrome(s, j, i - 1))
            {
                t = min(t, dp[j] + 1);
            }
        }
        dp[i] = t;
    }
    return dp[n] - 1;
}

int main(void)
{
    string s;
    cin >> s;
    cout << minCut(s) << "\n";
    return 0;
}

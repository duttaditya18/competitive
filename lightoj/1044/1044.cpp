#include <bits/stdc++.h>

using namespace std;

#define INF (INT_MAX/2)

string s;
int n;

bool isPalindrome(int st, int en)
{
    while(en > st)
    {
        if(s[st] != s[en]) return false;
        st++;
        en--;
    }
    return true;
}

int main(void)
{
    int te;
    cin >> te;

    int q = te;

    while(q--)
    {
        cin >> s;
        n = s.size();

        int dp[n + 1];
        for(int i = 0; i <= n; i++) dp[i] = INF;
        dp[0] = 0;

        for(int i = 1; i <= n; i++)
        {
            int t = INT_MAX;
            for(int j = i - 1; j >= 0; j--)
            {
                if(isPalindrome(j, i - 1))
                {
                    t = min(t, dp[j] + 1);
                }
            }
            dp[i] = t;
        }
        cout << "Case " << te - q << ": " << dp[n] << "\n";
    }
    return 0;
}

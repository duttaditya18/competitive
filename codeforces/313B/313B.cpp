#include <bits/stdc++.h>

using namespace std;
int dp[100005];
int main(void)
{
    string s;
    cin >> s;

    for(int i = 0, l = s.size(); i < l - 1; i++)
    {
        if(s[i] == s[i+1]) dp[i + 1]++;
        dp[i + 1] += dp[i];
    }

    //for(int i = 0; i < s.size(); i++) cout << dp[i];

    int m;
    cin >> m;

    int st, l;
    while(m--)
    {
        cin >> st >> l;
        cout << dp[l - 1] - dp[st - 1] << endl;
    }

}

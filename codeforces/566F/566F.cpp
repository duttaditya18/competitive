#include <bits/stdc++.h>

using namespace std;
#define MAXN 1000010

int n, c, mf, x;
int exist[MAXN], dp[MAXN];

int main(void)
{
    cin >> n;

    int ma = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        ma = max(ma, x);
        exist[x] = 1;
    }

    int ans = 0;

    for(int i = ma; i >= 1; i--)
    {
        if(!exist[i]) continue;
        dp[i] = 1;
        c = i;
        c += i;

        mf = 0;
        while(c <= ma)
        {
            mf = max(mf, dp[c]);
            c += i;
        }
        dp[i] += mf;
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
}

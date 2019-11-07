#include <bits/stdc++.h>

using namespace std;

int a[252];
int prf[252];

int dp[252][252];

int rec(int l, int r, int d)
{
    // for(int i = 0; i < d; i++) cout << " ";
    // cout << l << " " << r << " " << d << endl;

    if(l == r) return 0;

    if(dp[l][r] != -1) return dp[l][r];
    int mi = INT_MAX;
    for(int i = l; i <= r; i++)
    {
        if(i == l) mi = min(mi, rec(i + 1, r, d + 1) - a[i]);
        else if(i == r) mi = min(mi, rec(l, i - 1, d + 1) - a[i]);
        else mi = min(mi, rec(l, i - 1, d + 1) + rec(i + 1, r, d + 1) - a[i]);
    }
    dp[l][r] = mi + prf[r] - prf[l - 1];
    return dp[l][r];
}

int main(void)
{
    // ifstream cin("in.in");
    // ofstream cout("out.out");

    int n;
    while(cin >> n)
    {
        for(int i = 0; i <= n + 1; i++)
        {
            for(int j = 0; j <= n + 1; j++)
            {
                dp[i][j] = -1;
            }
        }
        a[0] = 0;
        prf[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            prf[i] = a[i];
            prf[i] += prf[i - 1];
        }

        // for(int i = 0; i <= n; i++) cout << prf[i] << " "; cout << endl;

        a[n + 1] = 0;
        cout << rec(1, n, 0) << endl;
    }
}

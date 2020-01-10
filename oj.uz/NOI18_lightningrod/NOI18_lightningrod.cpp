#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
// #define getchar_unlocked getchar

void fastscan(int &x)
{
    bool neg=false;
    register int c;
    x =0;
    c=getchar_unlocked();
    if(c=='-')
    {
        neg = true;
        c=getchar_unlocked();
    }
    for(;(c>47 && c<58);c=getchar_unlocked())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *=-1;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    fastscan(n);

    // x, y
    int x, y;
    pair<int, int> p[n + 1];

    for(int i = 1; i <= n; i++)
    {
        fastscan(p[i].fi);
        fastscan(p[i].se);
    }

    int suf[n + 2] = {};
    int prf[n + 2] = {};

    prf[0] = INT_MIN;
    prf[n + 1] = INT_MIN;

    suf[0] = INT_MAX;
    suf[n + 1] = INT_MAX;

    for(int i = 1; i <= n; i++)
        prf[i] = max(prf[i - 1], p[i].fi + p[i].se);


    for(int i = n; i >= 1; i--)
        suf[i] = min(suf[i + 1], p[i].fi - p[i].se);


    int ans = n;
    for(int i = 1; i <= n; i++)
        ans -= ((p[i].fi + p[i].se <= prf[i - 1]) || (p[i].fi - p[i].se >= suf[i + 1]));
    cout << ans << endl;
}

#include <bits/stdc++.h>

using namespace std;
#define MAXN 510

int n, m, b, mod;
int a[MAXN];

// programmers, lines, bugs
int rec(int pn, int pm, int pb, int px)
{
    for(int i = 0; i < px; i++) cout << "  "; cout << pn << " " << pm << " " << pb << " " << endl;

    if(pn == n)
    {
        if(pm == 0 && pb <= b) return 1;
        return 0;
    }

    int ans = 0;
    for(int i = 0; i <= pm; i++)
    {
        if(pb + (a[i]*i) > b || pm - i < 0) break;
        ans += rec(pn + 1, pm - i, pb + (a[pn] * i), px + 1);
    }
    return ans;
}

int main(void)
{
    cin >> n >> m >> b >> mod;

    for(int i = 0; i < n; i++) cin >> a[i];
    cout << rec(0, m, 0, 0);
}

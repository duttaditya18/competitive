#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, l, r, x; cin >> n >> l >> r >> x;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    int to, ma, mi, ans = 0;
    for(int mask = 1; mask < (1 << n); mask++)
    {
        to = 0;
        ma = INT_MIN;
        mi = INT_MAX;
        if(__builtin_popcount(mask) == 1) continue;
        for(int i = 0; i < n; i++)
        {
            if(mask & (1 << i))
            {
                to += a[i];
                ma = max(ma, a[i]);
                mi = min(mi, a[i]);
            }
        }
        // cout << to << ' ' << ma << ' ' << mi << "\n";
        if(to >= l && to <= r && (ma - mi) >= x) ans++;
    }
    cout << ans << "\n";
}

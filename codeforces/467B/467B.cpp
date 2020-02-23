#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m, k, x, ans = 0; cin >> n >> m >> k;
    int a[m];
    for(int i = 0; i < m; i++) cin >> a[i]; cin >> x;
    for(int i = 0; i < m; i++)
    {
        // cout << __builtin_popcount(a[i]^x) << "\n";
        if(__builtin_popcount(a[i]^x) <= k) ans++;
    }
    cout << ans << "\n";
    return 0;
}

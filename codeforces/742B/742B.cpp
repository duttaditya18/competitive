#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

int main(void)
{
    map<int, int> m;
    int n, x; cin >> n >> x;
    int a[n];
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    if(x == 0)
    {
        for(auto u : m) ans += 1ll * (u.se - 1) * u.se / 2;
        cout << ans << "\n";
        return 0;
    }
    for(auto u : m) ans += 1ll * u.se * m[(u.fi ^ x)];
    cout << ans/2 << "\n";
    return 0;
}

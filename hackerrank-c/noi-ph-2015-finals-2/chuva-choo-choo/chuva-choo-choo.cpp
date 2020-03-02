#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void)
{
    int t; cin >> t;

    while(t--)
    {
        ll n, l, u; cin >> n >> l >> u;
        ll a[n] = {};
        vector<ll> v;
        for(int i = 0; i < n; i++) cin >> a[i];
        ll x = (n / 2), c;

        for(int m = 0; m < (1 << x); m++)
        {
            // cout << m << endl;
            c = 0;
            for(int j = 0; j < x; j++) if(m & (1 << j)) c += a[j];
            v.push_back(c);
        }
        sort(v.begin(), v.end());
        // for(auto u : v) cout << u << " "; cout << "\n";
        // cout << v.size() << endl;
        // cout << endl;
        x = n - (n / 2);
        // cout << x << endl;
        ll ans = 0;
        for(int m = 0; m < (1 << x); m++)
        {
            c = 0;
            for(int j = 0; j < x; j++) if(m & (1 << j)) c += a[j + (n / 2)];
            int lwr = lower_bound(v.begin(), v.end(), l - c) - v.begin();
            int upr = upper_bound(v.begin(), v.end(), u - c) - 1 - v.begin();
            // cout << c << " " << lwr << " " << upr << "\n";
            if(!(c > u)) ans += (upr - lwr + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}

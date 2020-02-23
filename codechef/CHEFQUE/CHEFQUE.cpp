#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll man = 4294967296;
const ll mod = 4294967296;

// bitset<100> bs;
bitset<man> bs;

int main(void)
{
    ll q, s, a, b; cin >> q >> s >> a >> b;

    ll ans = 0;

    while(q--)
    {
        if(s % 2)
        {
            ans += (s / 2);
            bs[s / 2] = 1;
        }
        else
        {
            if(bs[s / 2])
            {
                ans -= (s / 2);
                bs[s / 2] = 0;
            }
        }
        s = ((a * s) + b) % mod;
    }

    cout << ans << "\n";
    return 0;
}

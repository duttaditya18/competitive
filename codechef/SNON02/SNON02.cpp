#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll maxn = 1e6;

ll a[maxn + 10];
ll b[maxn + 10];

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    a[1] = 1;

    for(ll i = 2; i <= maxn; i++) a[i] = i - 1;

    for(ll i = 2; i <= maxn; i++)
        for(ll j = i + i; j <= maxn; j += i)
            a[j] -= a[i];

    b[1] = 1;
    for(ll i = 1; i <= maxn; i++)
    {
        for(ll j = i + i; j <= maxn; j += i)
        {
            b[j] += (j * j * a[j / i]) / i;
        }
    }

    ll t, n; cin >> t;
    while(t--)
    {
        cin >> n;
        cout << (b[n] / 2) + n << "\n";
    }
}

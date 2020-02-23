#include <bits/stdc++.h>

using namespace std;
#define int long long

int phi(int n)
{
    int result = n;
    for (int p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

signed main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    int t, a, m; cin >> t;

    while(t--)
    {
        cin >> a >> m;
        cout << phi(m/__gcd(a, m)) << "\n";
    }
    return 0;
}

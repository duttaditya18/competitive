#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e6 + 3;

long long fact[mod + 5];
long long int t, n, m;

int main(void)
{
    fact[0] = 1;
    for(int i = 1; i <= mod; i++)
        fact[i] = (fact[i - 1] * i) % mod;

    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        cout << (fact[min(n, mod)]*m) % mod;
        cout << "\n";
    }
    return 0;
}

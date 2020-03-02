#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

int main(void)
{
    int t; cin >> t;

    while(t--)
    {
        long long n; cin >> n;
        n %= mod;
        cout << (n * n) % mod << "\n";
    }
    return 0;
}

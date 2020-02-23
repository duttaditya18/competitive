#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll a)
{
    if(a == 0) return 0;
    if(a == 1) return 1;
    if(a == 2) return 3;
    if(__builtin_popcountll(a) == 1) return a;
    if(__builtin_popcountll(a) == (64 - __builtin_clzll(a))) return 0;
    if(!(a % 2)) return (1LL << (64 - __builtin_clzll(a) - 1)) + f(a - (1LL << (64 - __builtin_clzll(a) - 1)));
    else return f(a - (1LL << (64 - __builtin_clzll(a) - 1)));
}

int main(void)
{
    ll a, b; cin >> a >> b;
    cout << (f(b) ^ f(a - 1));
    cout << "\n";
    return 0;
}

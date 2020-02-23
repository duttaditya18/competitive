#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll rec(ll n, ll k)
{
    // cout << n << " " << k << endl;
    if(k < (1LL << (n - 1))) return rec(n - 1, k);
    else if(k > (1LL << (n - 1))) return rec(n - 1, k - (1LL << (n - 1)));
    else if(k == (1LL << (n - 1))) return n;
}

int main(void)
{
    ll n, k; cin >> n >> k;
    cout << rec(n, k) << "\n";
    return 0;
}

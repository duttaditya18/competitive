#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll rec(ll n, ll k)
{
    // cout << n << " " << k << endl;
    if(k < (1LL << (n - 1))) return rec(n - 1, k);
    else if(k > (1LL << (n - 1))) return rec(n - 1, k - (1LL << (n - 1)));
    else return n;
}

int main(void)
{
    ll n, k; cin >> n >> k;

    while(n >= 0)
    {
        // cout << n << " " << k << endl;
        if(k > (1LL << (n - 1))) k -= (1LL << (n - 1));
        else if(k == (1LL << (n - 1)))
        {
            cout << n << "\n";
            return 0;
        }
        n--;
    }
    return 0;
}

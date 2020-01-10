#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long x; cin >> x;

    long long mi = LLONG_MAX;

    for(long long i = 1; i*i <= x; i++)
    {
        if(!(x % i) && __gcd(i, x / i) == 1)
        {
            mi = min(mi, max(i, x / i));
        }
    }

    cout << min(x/mi, mi) << " " << max(x/mi, mi) << endl;
}

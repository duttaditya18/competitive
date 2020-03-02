#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void)
{
    ll n; cin >> n;
    cout << ((n * n * (n + 1)) / 2) - ((n * (n + 1) * (2 * n + 1)) / 6) + n << "\n";
    return 0;
}

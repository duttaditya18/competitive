#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void)
{
    ifstream cin("moobuzz.in");
    ofstream cout("moobuzz.out");

    ll n; cin >> n; n--;
    ll g[] = {1, 2, 4, 7, 8, 11, 13, 14};
    ll ans = ((n / 8) * 15);
    cout << ((n / 8) * 15) + g[n % 8] << "\n";
    return 0;
}

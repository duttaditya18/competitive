#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;

int main(void) {
	string s; cin >> s;
	int n = s.size();

	ll ans = 0, pot = 1, por = 0;
	for (int i = n - 1; i >= 0; i--) {
		ll c1 = (((((1ll * i) * (i + 1)) / 2) % mod) * pot) % mod;
		ll cur = (s[i] - '0') * ((c1 + por) % mod) % mod;
		ans = (ans + cur) % mod;
		por = (por + ((pot * (n - i)) % mod)) % mod;
		pot = (pot * 10) % mod;
	}
	cout << ans << "\n";
	return 0;
}

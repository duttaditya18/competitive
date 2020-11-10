#include <bits/stdc++.h>

using namespace std;
const int maxs = 1010;
const int mod = 1e9 + 7;
typedef long long ll;

int a[maxs + 100];
int cnt[maxs + 100] = {};
ll ncr[maxs + 100][maxs + 100] = {};

int main(void) {
	string s; cin >> s;
	int n = s.size(), pc = 0;

	for (int i = 0; i < n; i++) {
		a[i] = (s[i] - '0');
		pc += a[i];
	}

	int k; cin >> k;
	if (k == 0) {
		cout << 1 << "\n";
		return 0;
	}

	for (int i = 0; i <= maxs; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == 0 || j == 0) {
				ncr[i][j] = 1;
			} else {
				ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % mod;
			}
		}
	}

	ll ans = 0;
	for (int i = 1; i <= min(n, maxs); i++) {
		if (i == 1) {
			cnt[i] = 0;
		} else {
			cnt[i] = cnt[__builtin_popcount(i)] + 1;	
		}

		if (cnt[i] == k - 1) {
			int c = 0;
			for (int j = 0; j < n; j++) {
				if (a[j]) {
					if (i >= c) {
						ans = (ans + ncr[n - j - 1][i - c]) % mod;
					}
					c++;
				}
			}
		}
	}
	cout << ans - (k == 1) + (cnt[pc] == k - 1) << '\n';

	return 0;
}

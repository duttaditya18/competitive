#include <bits/stdc++.h>

using namespace std;
const int maxs = 1010;
const int mod = 1e9 + 7;
typedef long long ll;

int n, sumdo;
int a[maxs + 100];
int dp[maxs + 100][maxs + 100][5];

ll rec(int cur, int sum, int edg) {
	if (sum > sumdo) {
		return 0;
	}
	if (cur == n) {
		return (sum == sumdo);
	}
	if (dp[cur][sum][edg] == -1) {
		ll res = 0;
		for (int i = 0; i <= (edg ? a[cur] : 1); i++) {
			res = (res + rec(cur + 1, sum + i, edg && i == a[cur])) % mod;
		}
		dp[cur][sum][edg] = res;
	}
	return dp[cur][sum][edg];
}

int main(void) {
	string s; cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++) {
		a[i] = (s[i] - '0');
	}

	int k; cin >> k;
	if (k == 0) {
		cout << 1 << "\n";
		return 0;
	}

	int cnt[maxs + 100] = {};

	ll ans = 0;
	for (int i = 1; i <= min(n, maxs); i++) {
		if (i == 1) {
			cnt[i] = 0;
		} else {
			cnt[i] = cnt[__builtin_popcount(i)] + 1;	
		}

		if (cnt[i] == k - 1) {
			for (int io = 0; io < maxs; io++) {
				for (int jo = 0; jo < maxs; jo++) {
					for (int ko = 0; ko < 2; ko++) {
						dp[io][jo][ko] = -1;
					}
				}
			}
			sumdo = i;
			ans = (ans + rec(0, 0, 1)) % mod;
		}
	}
	cout << ans - (k == 1) << '\n';

	return 0;
}

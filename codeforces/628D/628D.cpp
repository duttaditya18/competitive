#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mod = 1e9 + 7;
const int maxn = 2010;

int m, d, na, nb;
string sa, sb;
int a[maxn], b[maxn];
int dp[maxn][maxn][2];

int rec(int cur, int rem, int edg) {
	if (dp[cur][rem][edg] == -1) {
		int rans;
		if (cur == na) {
			if (!rem) {
				rans = 1;
			} else {
				rans = 0;
			}
		} else {
			if (!(cur % 2)) {
				int ans = 0;
				for (int i = 0; i <= (edg ? a[cur] : 9); i++) {
					if (i != d) {
						ans = (ans + rec(cur + 1, (rem * 10 + i) % m, edg && (i == a[cur]))) % mod;
					}
				}
				rans = ans;
			} else {
				if (edg && d > a[cur]) {
					rans = 0;
				} else {
					rans = rec(cur + 1, (rem * 10 + d) % m, d == a[cur]);
				}
			}
		}
		dp[cur][rem][edg] = (rans % mod);
	}
	return dp[cur][rem][edg];
}

void clear() {
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxn; j++) {
			for (int k = 0; k < 2; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
}

signed main(void) {
	cin >> m >> d;
	cin >> sa; cin >> sb;
	na = sa.size(); nb = sb.size();
	
	int ifsat = 1, rem = 0;
	for (int i = 0; i < na; i++) {
		a[i] = sa[i] - '0';
		if (((i % 2) && a[i] != d) || (!(i % 2) && a[i] == d)) {
			ifsat = 0;
		}
		rem = (rem * 10 + a[i]) % m; 
	}
	ifsat &= (!rem);

	for (int i = 0; i < nb; i++) {
		b[i] = sb[i] - '0';
	}

	clear();
	int xa = rec(0, 0, 1);

	clear();
	for (int i = 0; i < nb; i++) {
		a[i] = b[i];
	}
	na = nb;
	int xb = rec(0, 0, 1);
	int ans = xb - xa + ifsat;
	cout << (ans + mod) % mod << "\n";
	return 0;
}

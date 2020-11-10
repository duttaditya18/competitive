#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

signed main(void) {
	int n, x; cin >> n;

	int a[n + 1] = {};
	int v[n + 1] = {};
	for (int i = 0; i < n; i++) {
		cin >> x;
		a[x]++;
		v[a[x]]++;
	}
	for (int i = 1; i <= n; i++) {
		v[i] += v[i - 1];
	}

	for (int k = 1; k <= n; k++ ) {
		int l = 0, r = n, ans = -1;

		while (l <= r) {
			int mid = l + (r - l) / 2;

			if (v[mid] >= (long long)(mid) * k) {
				l = mid + 1;
				ans = mid;
			} else {
				r = mid - 1;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}

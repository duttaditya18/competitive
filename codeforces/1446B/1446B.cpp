#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
string a, b;
int dp[5010][5010];

int main(void) {
	cin >> n >> m;
	cin >> a >> b;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = max(dp[i][j],
						dp[i - 1][j - 1] + 2);
			}
			dp[i][j] = max(dp[i][j],
					max(dp[i - 1][j], dp[i][j - 1]) - 1);
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << "\n";

	return 0;
}

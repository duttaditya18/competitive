#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t; cin >> t;

    while(t--)
    {
        int n, k; cin >> n >> k;

        int a[n] = {};

        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a, a + n);

        int ans = INT_MAX;

        for(int i = 0; i < n - k + 1; i++) ans = min(ans, a[i + k - 1] - a[i]);

        cout << ans << endl;
    }
}

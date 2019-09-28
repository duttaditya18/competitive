#include <bits/stdc++.h>

using namespace std;

int a[600000];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    long long ans = 0;;

    for(int i = 0; i < n; i++)
    {
        ans = max(ans, 1ll * a[i] * (n - i));
    }
    cout << ans;
    return 0;
}

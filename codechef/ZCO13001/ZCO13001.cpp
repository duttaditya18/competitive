#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n; cin >> n;

    int a[n];
    long long ans = 0;

    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    //for(int i = 0; i < n; i++) cout << a[i] << " ";

    for(int i = 1; i < n; i++)
    {
        ans += 1ll * (a[i] - a[i - 1]) * (i) * (n - i);
    }

    cout << ans << endl;
}

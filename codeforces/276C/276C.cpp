#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, q; cin >> n >> q;

    int a[n] = {}, b[n] = {}, x, y;

    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < q; i++)
    {
        cin >> x >> y;
        b[x - 1] += 1;
        if(y != n) b[y] -= 1;
    }

    for(int i = 1; i < n; i++) b[i] += b[i - 1];

    sort(a, a + n);
    sort(b, b + n);

    long long ans = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        if(!b[i]) break;
        ans += (1ll * a[i] * b[i]);
    }

    cout << ans << endl;

    // for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
    // for(int i = 0; i < n; i++) cout << b[i] << " "; cout << endl;
}

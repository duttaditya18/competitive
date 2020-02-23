#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

signed main(void)
{
    int n; cin >> n;
    int x; cin >> x;

    int a[n] = {};

    for(int i = 0; i < n; i++) cin >> a[i];

    int m[x + 1] = {};
    int ans = 0;

    for(int i = 1; i < n; i++)
    {
        if(a[i] > x) continue;
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] + a[j] > x) continue;
            if(m[x - a[i] - a[j]]) ans += m[x - a[i] - a[j]];
        }
        for(int j = i - 1; j >= 0; j--)
        {
            if(a[i] + a[j] > x) continue;
            m[a[i] + a[j]]++;
        }
    }
    cout << ans << "\n";
    return 0;
}

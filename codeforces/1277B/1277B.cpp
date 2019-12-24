#include <bits/stdc++.h>

using namespace std;
#define MAXN 200010

int q, n, y, x;
int a[MAXN];

int main(void)
{
    cin >> q;

    while(q--)
    {
        unordered_map<int, int> m;
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            cin >> y;
            x = __builtin_ctz(y);
            m[y >> x] = max(m[y >> x], x);
        }

        int ans = 0;

        for(auto u : m) ans += u.second;

        cout << ans << endl;
    }
    return 0;
}

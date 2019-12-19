#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        int a[3] = {};
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);

        if(a[0] + a[1] <= a[2])
        {
            cout << a[0] + a[1] << endl;
            continue;
        }

        int ans = 0;

        // cout << a[0] << " " << a[1] << " " << a[2] << " " << ans << endl;

        ans += (a[1] - a[0]);
        a[2] -= (a[1] - a[0]);
        a[1] = a[0];

        // cout << a[0] << " " << a[1] << " " << a[2] << " " << ans << endl;

        ans += 2 * (a[2] - a[1]);
        a[1] -= (a[2] - a[1]);
        a[2] -= 2*(a[2] - a[0]);
        a[0] = a[1];

        // cout << a[0] << " " << a[1] << " " << a[2] << " " << ans << endl;

        if(a[0] == 0)
        {
            cout << ans << endl;
            continue;
        }
        else
        {
            ans += 3 * (a[0] / 2);
            if(a[0] % 2) ans++;
            cout << ans << endl;
            continue;
        }
    }
    return 0;
}

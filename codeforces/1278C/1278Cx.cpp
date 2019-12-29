#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;

        // 1 = 1, 2 = -1
        int a[n + 1] = {}, b[n + 1] = {};
        for(int i = n; i >= 1; i--)
        {
            cin >> a[i];
            a[i] = (a[i] == 2 ? -1 : 1);
        }
        for(int i = 1; i <= n; i++) a[i] += a[i - 1];

        unordered_map<int, int> ma;
        for(int i = 1; i <= n; i++)
        {
            cin >> b[i];
            b[i] = (b[i] == 2 ? -1 : 1);
            b[i] += b[i - 1];
        }

        for(int i = n; i >= 0; i--) ma[b[i]] = i;
        int sum = (a[n] + b[n]), ans = INT_MAX;

        for(int i = 0; i <= n; i++)
        {
            if(ma.find(sum - a[i]) != ma.end())
            {
                // cout << i << " " << a[i] << " " << sum - a[i] << " " << ma[sum - a[i]] << endl;
                ans = min(ans, i + ma[sum - a[i]]);
            }
        }
        cout << ans << endl;

        // for(int i = 0; i <= n; i++) cout << a[i] << " "; cout << endl;
        // for(int i = 0; i <= n; i++) cout << b[i] << " "; cout << endl;
        // cout << sum << endl;
    }
}

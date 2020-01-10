#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007

int main(void)
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int ans = 1, ma = INT_MIN;

        int a[n + 2] = {};

        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            ma = max(ma, a[i]);
        }
        if(ma == 0)
        {
            cout << 0 << endl; continue;
        }
        for(int i = 1; i <= n; i++)
        {
            if(a[i] == 1)
            {
                if(a[i - 1] > a[i - 2])
                {
                    a[i - 1]++;
                    a[i]--;
                }
                else
                {
                    a[i + 1]++;
                    a[i]--;
                }
            }
        }
        for(int i = 1; i <= n; i++) ans = (ans * max(1, a[i])) % MOD;
        cout << ans << endl;
    }
}
